/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:55:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/29 13:55:50 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

void			term_write_prompt(t_term *term)
{
	int			col;
	t_winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	col = ft_strlen(term->line_edit.prompt);
	col += term->line_edit.cur;
	col %= w.ws_col;
	ft_putstr(term->line_edit.prompt);
	ft_putstr(term->line_edit.text);
	term_exec_tc("cr");
	term_exec_goto("ch", 0, col);
}

void			term_refresh(t_term *term)
{
	int			line;
	t_winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	line = ft_strlen(term->line_edit.prompt);
	line += term->line_edit.len;
	line /= w.ws_col;
	while (line--)
		term_exec_tc("up");
	term_exec_tc("cr");
	term_exec_tc("cd");
}
