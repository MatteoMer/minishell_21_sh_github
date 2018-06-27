/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_event5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:09:50 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/26 19:15:59 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

int					term_evt_cut(t_term *term)
{
	ft_strcpy(term->paste_buf, term->line_edit.text);
	return (term_evt_cancel(term));
}
