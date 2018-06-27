/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:58:52 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/27 17:51:40 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				ps_exp_dollar(t_list **tokens)
{
	char		*tmp;
	char		*ptr;

	ptr = (*tokens)->content;
	tmp = ft_strdup(env_get(ft_strchr((*tokens)->content, '$') + 1));
	(*tokens)->content = ft_strdup(tmp);
	free(ptr);
	free(tmp);
	return (0);
}

int				ps_exp_tilde(t_list **tokens)
{
	char		*tmp;
	char		*ptr;

	ptr = ft_strdup((*tokens)->content + 1);
	free((*tokens)->content);
	tmp = ft_strdup(env_get("HOME"));
	if (!tmp || env_get("HOME") == NULL)
	{
		ft_putendl("minishell: can't use `~`, $HOME is not defined.");
		return (-1);
	}
	(*tokens)->content = ft_strjoinf(tmp, ptr);
	free(ptr);
	return (0);
}

int				ps_expansion(t_list **tokens)
{
	t_list		*start;
	char		*ptr;

	start = *tokens;
	while (*tokens)
	{
		if ((*tokens)->content_size == 3)
		{
			ptr = ft_strchr((*tokens)->content, '$');
			if (ptr != NULL && ptr[1] != '\0')
				return (ps_exp_dollar(tokens));
			else if (((char *)(*tokens)->content)[0] == '~')
				return (ps_exp_tilde(tokens));
		}
		*tokens = (*tokens)->next;
	}
	*tokens = start;
	return (0);
}
