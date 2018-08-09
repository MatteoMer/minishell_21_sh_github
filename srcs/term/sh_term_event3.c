/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_event3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:55:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 19:25:14 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

int				term_evt_cancel(t_term *term)
{
	term_le_clear(&term->line_edit);
	term->ctn = 0;
	term_exec_tc("cr");
	return (0);
}

int				term_evt_end(t_term *term)
{
	if (term->line_edit.cur == term->line_edit.len)
		return (-1);
	term->line_edit.cur = term->line_edit.len;
	return (0);
}

int				term_evt_home(t_term *term)
{
	if (term->line_edit.cur == 0)
		return (-1);
	term->line_edit.cur = 0;
	return (0);
}

int				term_evt_interrupt(t_term *term)
{
	term->ctn = -1;
	return (0);
}
