/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:55:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/12 19:55:41 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

void				term_exec_tc(char *str)
{
	char		*s;

	s = tgetstr(str, NULL);
	if (s)
		write(1, s, ft_strlen(s));
}

void				term_exec_goto(char *str, int x, int y)
{
	char		*s;

	s = tgoto(tgetstr(str, NULL), x, y);
	write(1, s, ft_strlen(s));
}

void				term_get_pos(t_term *term, int *x, int *y)
{
	struct termios	term_ios;
	char			str[16];

	term_ios = term->term_ios;
	term_ios.c_cc[VMIN] = 6;
	term_ios.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term_ios);
	write(1, "\033[6n", 4);
	read(0, str, 16);
	tcsetattr(0, TCSANOW, &(term->term_ios));
	*y = ft_atoi(str + 2) - 1;
	*x = ft_atoi(ft_strchr(str, ';') + 1) - 1;
}
