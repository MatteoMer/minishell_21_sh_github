/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_event4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:21:49 by mdelory           #+#    #+#             */
/*   Updated: 2018/06/23 17:01:46 by mmervoye         ###   ########.fr       */
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
	ft_putendl("haha");
	(void)term;
	term_exec_tc("cl");
	return (0);
}
