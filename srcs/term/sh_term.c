/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:44:34 by mdelory           #+#    #+#             */
/*   Updated: 2018/06/23 17:26:47 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

char			*term_main_loop(t_term *term)
{
	char		kc;
	int			rd;

	if (tcsetattr(0, TCSADRAIN, &(term->term_ios)) == -1)
		return (NULL);
	if (!(term->history) || term->history->text != term->buffer)
		term_hst_add_entry(&(term->history), term->buffer);
	term_le_clear(&(term->line_edit));
	term->ctn = 1;
	while (term->ctn > 0)
	{
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &(term->wsize));
		term_write_prompt(term);
		rd = read(0, &kc, 1);
		term_read_input(term, kc, rd);
		term_refresh(term);
	}
	tcsetattr(0, TCSADRAIN, &(term->old_ios));
	term_hst_goto_head(&(term->history));
	if (term->ctn == -1)
		return (NULL);
	if (term->line_edit.len != 0)
		term->history->text = ft_strdup(term->line_edit.text);
	return (term->line_edit.text);
}

void			term_write_prompt(t_term *term)
{
	int			col;

	term_exec_tc("sc");
	col = ft_strlen(term->line_edit.prompt);
	col += term->line_edit.cur;
	col %= term->wsize.ws_col;
	term_set_fcolor(255, 204, 0);
	ft_putstr(term->line_edit.prompt);
	term_reset_color();
	ft_putstr(term->line_edit.text);
	term_exec_tc("cr");
	term_exec_goto("ch", 0, col);
}

void			term_refresh(t_term *term)
{
	if (term->idle == 1 && term->line_edit.cur == term->line_edit.len)
		term_exec_tc("vi");
	else
		term_exec_tc("ve");
	term_exec_tc("cr");
	term_exec_tc("cd");
}

int				term_read_input(t_term *term, char kc, int rd)
{
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
		return (-1);
	if (tcgetattr(0, &(term->term_ios)))
		return (-1);
	term->line_edit.prompt = "(minishell) -> ";
	term->history = NULL;
	term->idle = 0;
	term->old_ios = term->term_ios;
	term->term_ios.c_iflag &= ~(ICRNL | IXON);
	term->term_ios.c_lflag &= ~(ICANON | ECHO | IEXTEN | ISIG);
	term->term_ios.c_cc[VMIN] = 0;
	term->term_ios.c_cc[VTIME] = 5;
	return (0);
}
