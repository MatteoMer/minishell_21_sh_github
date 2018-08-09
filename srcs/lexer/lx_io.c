/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:42:34 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 18:12:39 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			lx_check_io(char *buf, t_list **tokens)
{
	if (ft_isdigit(*buf) && (*(buf + 1) == '>' || *(buf + 1) == '<'))
		return (lx_new_io(buf, tokens));
	else
		return (lx_new_word(buf, tokens));
}

int			lx_new_io(char *buf, t_list **tokens)
{
	t_list		*new;

	if ((new = ft_lstnew(NULL, 0)) == NULL)
		malloc_error();
	if ((new->content = ft_strnew(1)) == NULL)
		malloc_error();
	((char *)new->content)[0] = *buf;
	((char *)new->content)[1] = '\0';
	new->content_size = 4;
	ft_lstadd(tokens, new);
	return (1);
}
