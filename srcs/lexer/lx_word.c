/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:17:09 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 18:14:35 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			lx_new_word(char *buf, t_list **tokens)
{
	t_list		*new;
	char		*tmp;

	if ((new = ft_lstnew(NULL, 0)) == NULL)
		malloc_error();
	if ((tmp = ft_strtrim(buf)) == NULL)
		malloc_error();
	if ((new->content = lx_strdup(tmp)) == NULL)
		malloc_error();
	new->content_size = 3;
	ft_lstadd(tokens, new);
	ft_strdel(&tmp);
	return (ft_strlen(new->content));
}
