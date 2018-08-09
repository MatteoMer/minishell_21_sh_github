/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:58:52 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 18:15:22 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				ps_exp_dollar(t_list **tokens)
{
	char		*tmp;
	char		*ptr;

	ptr = (*tokens)->content;
	if (ptr[1] == '\0')
		return (-1);
	if ((tmp = ft_strdup(env_get(ft_strchr((*tokens)->content, '$') + 1))) == NULL)
		malloc_error();
	if (((*tokens)->content = ft_strdup(tmp)) == NULL)
		malloc_error();
	free(ptr);
	free(tmp);
	return (0);
}

int				ps_exp_tilde(t_list **tokens)
{
	char		*tmp;
	char		*ptr;

	if ((ptr = ft_strdup((*tokens)->content + 1)) == NULL)
		malloc_error();
	free((*tokens)->content);
	if ((tmp = ft_strdup(env_get("HOME"))) == NULL)
		malloc_error();
	if (!tmp || env_get("HOME") == NULL)
	{
		ft_putendl("minishell: can't use `~`, $HOME is not defined.");
		return (-1);
	}
	if (((*tokens)->content = ft_strjoinf(tmp, ptr)) == NULL)
		malloc_error();
	free(ptr);
	return (0);
}

int				ps_expansion(t_list **tokens)
{
	t_list		*start;

	start = *tokens;
	while (*tokens)
	{
		if ((*tokens)->content_size == 3)
		{
			if (ft_strchr((*tokens)->content, '$'))
				return (ps_exp_dollar(tokens));
			else if (((char *)(*tokens)->content)[0] == '~')
				return (ps_exp_tilde(tokens));
		}
		*tokens = (*tokens)->next;
	}
	*tokens = start;
	return (0);
}
