/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:22:50 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/09 17:15:12 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				ps_parse_redir(t_list *tokens)
{
	int			i;

	i = 5;
	while (i < 9)
	{
		if (ps_parse_redir_check(tokens, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int				ps_parse_redir_check(t_list *tokens, int i)
{
	char		c;
	t_list		*tmp;
	t_list		*prev;

	c = i;
	if (tokens->content_size == (size_t)c)
		return (ps_error(c));
	tmp = tokens->next;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (tmp->content_size == (size_t)c && tokens->content_size == (size_t)c)
			return (ps_error(c));
		if (tmp->content_size == (size_t)c && tmp->content &&
				lx_is_op(((char*)tokens->content)[0]))
			return (ps_error(c));
		prev = tokens;
		tmp = tmp->next;
		tokens = tokens->next;
	}
	return (0);
}
