/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:46:10 by mdelory           #+#    #+#             */
/*   Updated: 2018/06/26 13:35:44 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

void		term_exec_tc(char *str)
{
	char		*s;

	s = tgetstr(str, NULL);
	write(1, s, ft_strlen(s));
}

void		term_exec_goto(char *str, int x, int y)
{
	char		*s;

	s = tgoto(tgetstr(str, NULL), x, y);
	write(1, s, ft_strlen(s));
}

void		term_set_bcolor(unsigned char r, unsigned char g, unsigned char b)
{
	write(1, "\x1B[48;", 5);
	write(1, "2;", 2);
	ft_putnbr(r);
	write(1, ";", 1);
	ft_putnbr(g);
	write(1, ";", 1);
	ft_putnbr(b);
	write(1, "m", 1);
}

void		term_set_fcolor(unsigned char r, unsigned char g, unsigned char b)
{
	write(1, "\x1B[38;", 5);
	write(1, "2;", 2);
	ft_putnbr(r);
	write(1, ";", 1);
	ft_putnbr(g);
	write(1, ";", 1);
	ft_putnbr(b);
	write(1, "m", 1);
}

void		term_reset_color(void)
{
	write(1, "\x1B[0m", 4);
}
