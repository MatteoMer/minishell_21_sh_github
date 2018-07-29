/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_event5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:31:00 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/29 18:20:55 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

int					term_evt_paste(t_term *term)
{
	char		line[LINE_MAX];

	if ((term->line_edit.len) + ft_strlen(term->c_buffer) >= LINE_MAX)
		return (-1);
	ft_strcpy(line, term->line_edit.text + term->line_edit.cur);
	ft_bzero(term->line_edit.text + term->line_edit.cur,\
ft_strlen(term->line_edit.text + term->line_edit.cur));
	ft_strcat(term->line_edit.text, term->c_buffer);
	ft_strcat(term->line_edit.text, line);
	term->line_edit.len = ft_strlen(term->line_edit.text);
	return (0);
}
