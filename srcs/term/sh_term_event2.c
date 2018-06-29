/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_event2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:55:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/29 14:25:04 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

int				term_evt_uparrow(t_term *term)
{
	if (term->history->text == term->buffer)
	{
		ft_bzero(term->buffer, ft_strlen(term->buffer));
		ft_strncpy(term->buffer, term->line_edit.text, term->line_edit.len);
	}
	if (term_hst_older(&(term->history), term->buffer) == 0)
	{
		term_le_set_text(&(term->line_edit), term->history->text);
		return (0);
	}
	return (-1);
}

int				term_evt_downarrow(t_term *term)
{
	if (term_hst_newer(&(term->history), term->buffer) == 0)
	{
		term_le_set_text(&(term->line_edit), term->history->text);
		return (0);
	}
	return (-1);
}

int				term_evt_leftarrow(t_term *term)
{
	return (term_le_move_bwd(&(term->line_edit)));
}

int				term_evt_rightarrow(t_term *term)
{
	return (term_le_move_fwd(&(term->line_edit)));
}

int				term_evt_ht(t_term *term)
{
	(void)term;
	return (0);
}
