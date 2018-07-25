/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_event4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:55:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/13 16:49:42 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

int					term_evt_alt_leftarrow(t_term *term)
{
	return (term_le_move_prev_word(&(term->line_edit)));
}

int					term_evt_alt_rightarrow(t_term *term)
{
	return (term_le_move_next_word(&(term->line_edit)));
}

int					term_evt_clear(t_term *term)
{
	(void)term;
	term_exec_tc("cl");
	term->p_y = 0;
	return (0);
}