/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_quoting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:05:23 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 18:13:51 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h> //

static int				lx_wlenquote(char *buf)
{
	int		i;
	char		c;

	i = 0;
	c = *buf;
	buf++;
	while (*buf)
	{
		i++;
		if (*buf == c)
			return (i);
		buf++;
	}
	ft_putendl("Unmatched \".");
	return (-1);
}

int						lx_quote(char *buf, t_list **tokens)
{
	t_list		*new;
	int			i;
	int			len;

	if ((len = lx_wlenquote(buf)) == -1)
		return (-1);
	i = 0;
	if ((new = ft_lstnew(NULL, 0)) == NULL)
		malloc_error();
	if ((new->content = ft_strnew(len + 1)) == NULL)
		malloc_error();
	new->content_size = 3;
	++len;
	while (len--)
	{
		((char*)new->content)[i] = *buf;
		i++;
		buf++;
	}
	((char*)new->content)[i] = '\0';
	ft_lstadd(tokens, new);
	return (ft_strlen((*tokens)->content));
}
