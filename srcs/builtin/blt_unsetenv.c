/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:21:03 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/22 18:54:18 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		free_it_pls(t_env **del)
{
	ft_strdel(&((*del)->value));
	ft_strdel(&((*del)->name));
	free(*del);
}

int				blt_unsetenv(char **cmd)
{
	t_env	*tmp;
	t_env	*prev;
	t_env	*del;

	prev = NULL;
	tmp = g_env;
	if (blt_error(cmd, 0) != 0)
		return (1);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, *cmd) == 0)
		{
			del = tmp;
			if (!prev)
				g_env = tmp->next;
			else
				prev->next = tmp->next;
			free_it_pls(&del);
			return (2);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}
