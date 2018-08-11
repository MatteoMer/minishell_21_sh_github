/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:13:16 by xmazella          #+#    #+#             */
/*   Updated: 2018/08/11 07:16:00 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void				free_it_pls(t_env **del)
{
	ft_strdel(&((*del)->value));
	ft_strdel(&((*del)->name));
	free(*del);
}

static int				blt_do_unset(char **cmd)
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

int						blt_unset(char **cmd)
{
	if (*cmd[0] == '-')
	{
		if (!ft_strcmp("-f", *cmd))
		{
			ft_putendl_fd("21sh: unset: function are not managed", 2);
			return (1);
		}
		else if (!ft_strcmp("-v", *cmd))
			return (blt_do_unset(cmd + 1));
		else
		{
			ft_putendl_fd("21sh: unset: usage: unset [-fv] {arg}", 2);
			return (1);
		}
	}
	else
		blt_do_unset(cmd);
	return (1);
}
