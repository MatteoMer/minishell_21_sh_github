/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:55:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/11 21:03:48 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

char			*term_main_loop(t_term *term)
{
	if (tcsetattr(0, TCSANOW, &(term->term_ios)) == -1)
		return (NULL);
	if (!(term->history) || term->history->text != term->buffer)
		term_hst_add_entry(&(term->history), term->buffer);
	term_le_clear(&(term->line_edit));
	term->ctn = 1;
	term_get_pos(term, &(term->p_x), &(term->p_y));
	while (term->ctn > 0)
	{
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &(term->wsize));
		term_write_prompt(term);
		term_read_input(term);
		term_refresh(term);
	}
	tcsetattr(0, TCSANOW, &(term->old_ios));
	term_hst_goto_head(&(term->history));
	if (term->ctn == -1)
		return (NULL);
	if (term->line_edit.len != 0)
		term->history->text = ft_strdup(term->line_edit.text);
	return (term->line_edit.text);
}

void			term_write_prompt(t_term *term)
{
	int			x;
	int			y;

	term_exec_tc("cd");
	y = term->p_y;
	x = ft_strlen(term->line_edit.prompt) + term->line_edit.cur;
	y += x / term->wsize.ws_col;
	x %= term->wsize.ws_col;
	ft_putstr(term->line_edit.prompt);
	ft_putstr(term->line_edit.text);
	term_exec_goto("cm", x, y);
}

void			term_refresh(t_term *term)
{
	if (term->idle == 1 && term->line_edit.cur == term->line_edit.len)
		term_exec_tc("vi");
	else
		term_exec_tc("ve");
	term_exec_goto("cm", term->p_x, term->p_y);
}

int				term_read_input(t_term *term)
{
	char		kc;
	int			rd;

	kc = 0;
	rd = read(0, &kc, 1);
	if (rd > 0)
	{
		term->idle = 0;
		if (!ft_isprint(kc))
			return (term_evt_dispatch(term, kc));
		term_hst_goto_head(&(term->history));
		term_le_insert(&(term->line_edit), kc);
	}
	else
		term->idle = !term->idle;
	return (0);
}

int				term_init(t_term *term)
{
	char		*term_name;

	term_name = getenv("TERM");
	if (tgetent(NULL, term_name) <= 0)
		term_name = "xterm-256color";
	if (tgetent(NULL, term_name) <= 0)
		return (-1);
	if (tcgetattr(0, &(term->term_ios)))
		return (-1);
	term->line_edit.prompt = "21sh $> ";
	term->history = NULL;
	term->idle = 0;
	term->old_ios = term->term_ios;
	term->term_ios.c_iflag &= ~(ICRNL | IXON);
	term->term_ios.c_lflag &= ~(ICANON | ECHO | IEXTEN | ISIG);
	term->term_ios.c_cc[VMIN] = 0;
	term->term_ios.c_cc[VTIME] = 5;
	return (0);
}
