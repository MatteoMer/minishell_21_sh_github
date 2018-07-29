/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:55:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/29 15:36:40 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

int				term_evt_dispatch(t_term *term, char kc)
{
	int			(*handler)(t_term *);

	handler = NULL;
	if (kc == 0x03)
		handler = term_evt_cancel;
	else if (kc == 0x04)
		handler = term_evt_interrupt;
	else if (kc == 0x09)
		handler = term_evt_ht;
	else if (kc == 0x0D)
		handler = term_evt_lf;
	else if (kc == 0x7F)
		handler = term_evt_bspace;
	else if (kc == 0x1B)
		handler = g_term_evt_esc_dispatch();
	else if (kc == 0x0C)
		handler = term_evt_clear;
	else if (kc == 0x19)
		handler = term_evt_copy;
	else if (kc == 0x18)
		handler = term_evt_cut;
	else if (kc == 0x10)
		handler = term_evt_paste;
	if (!handler)
		return (-1);
	if ((*handler)(term) == -1)
		term_exec_tc("bl");
	return (0);
}

int				(*g_term_evt_esc_dispatch(void))(t_term *)
{
	char		seq[8];

	ft_bzero(seq, 8);
	read(0, seq, 8);
	if (seq[0] == '[')
	{
		if (seq[1] == 'A')
			return (term_evt_uparrow);
		if (seq[1] == 'B')
			return (term_evt_downarrow);
		if (seq[1] == 'C')
			return (term_evt_rightarrow);
		if (seq[1] == 'D')
			return (term_evt_leftarrow);
		if (seq[1] == 'F')
			return (term_evt_end);
		if (seq[1] == 'H')
			return (term_evt_home);
		if (seq[4] == 'C')
			return (term_evt_alt_rightarrow);
		if (seq[4] == 'D')
			return (term_evt_alt_leftarrow);
	}
	return (NULL);
}

int				term_evt_lf(t_term *term)
{
	if (term_le_check_quote(&(term->line_edit)) == 0)
	{
		term->ctn = 0;
		term_exec_tc("do");
		term_exec_tc("cr");
	}
	else
	{
		term->line_edit.cur = term->line_edit.len;
		term_le_insert(&(term->line_edit), '\n');
	}
	return (0);
}

int				term_evt_bspace(t_term *term)
{
	term_hst_goto_head(&(term->history));
	return (term_le_bspace(&(term->line_edit)));
}
