/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:16:22 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/13 13:56:03 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int				lx_redir(char *buf, t_list **tokens)
{
	int			len;

	len = 0;
	len += lx_new_redir(buf, tokens);
	return (len);
}

int				lx_new_redir(char *buf, t_list **tokens)
{
	t_list		*new;
	int			len;
	char		*c;

	len = 0;
	c = buf + 1;
	new = ft_lstnew(NULL, 0);
	if (*buf == '<')
		new->content_size = 5;
	if (*buf == '>')
		new->content_size = 6;
	if (*buf == '<' && *c == '<')
		new->content_size = 7;
	if (*buf == '>' && *c == '>')
		new->content_size = 8;
	ft_lstadd(tokens, new);
	if ((*(buf + 1)) == '&')
		len += lx_agreg(buf, tokens);
	if (*c == *buf)
		len += 2;
	else
		len += 1;
	return (len);
}
