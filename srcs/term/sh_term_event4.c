/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_event4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:55:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/11 07:28:25 by xmazella         ###   ########.fr       */
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
	term->row = 0;
	return (0);
}

int					term_evt_copy(t_term *term)
{
	ft_strcpy(term->c_buffer, term->line_edit.text + term->line_edit.cur);
	term->line_edit.len += ft_strlen(term->c_buffer);
	term->line_edit.cur += ft_strlen(term->c_buffer);
	return (0);
}

int					term_evt_cut(t_term *term)
{
	ft_strcpy(term->c_buffer, term->line_edit.text + term->line_edit.cur);
	ft_bzero(term->line_edit.text + term->line_edit.cur, \
			ft_strlen(term->line_edit.text + term->line_edit.cur));
	return (0);
}
