/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:40:22 by mmervoye          #+#    #+#             */
/*   Updated: 2018/04/18 19:48:30 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int				lx_check_op(char *buf)
{
	if (*buf == ';')
		return (0);
	if (*(buf + 1) == *buf)
		return (1);
	return (0);
}

int						lx_new_op(char *buf, t_list **tokens)
{
	t_list		*new;
	int			check;

	new = ft_lstnew(NULL, 0);
	check = lx_check_op(buf);
	new->content = check ? ft_strnew(2) : ft_strnew(1);
	((char *)new->content)[0] = *buf;
	((char *)new->content)[1] = check ? *buf : '\0';
	if (check)
		((char *)new->content)[2] = '\0';
	new->content_size = check ? *buf + 1 : *buf;
	ft_lstadd(tokens, new);
	return (ft_strlen(new->content));
}
