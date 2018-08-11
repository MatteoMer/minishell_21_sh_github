/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:42:29 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/11 07:25:37 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char		*ps_realloc_quote(t_list *node)
{
	char		*ret;
	char		*cur;
	size_t		i;

	i = -1;
	cur = node->content;
	ret = ft_strnew(ft_strlen(cur) - 2);
	if (!ret)
		return (NULL);
	cur++;
	while (++i < ft_strlen(cur) - 1)
		ret[i] = cur[i];
	free(node->content);
	return (ret);
}

int				ps_quotes(t_list **tokens)
{
	t_list		*tmp;

	tmp = *tokens;
	while ((*tokens)->next)
	{
		if ((*tokens)->content && ((((char *)(*tokens)->content))[0] \
			== '\"' || (((char *)(*tokens)->content))[0] == 39))
			if (((*tokens)->content = ps_realloc_quote(*tokens)) == NULL)
				return (-1);
		*tokens = (*tokens)->next;
	}
	*tokens = tmp;
	return (0);
}
