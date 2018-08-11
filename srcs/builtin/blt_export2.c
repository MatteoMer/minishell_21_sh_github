/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_export2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 22:50:09 by xmazella          #+#    #+#             */
/*   Updated: 2018/08/11 07:22:07 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		blt_export_error(char *cmd, int i)
{
	if (i == 0)
	{
		ft_putstr("21sh: export: ");
		ft_putstr(cmd);
		ft_putendl(": invalid option");
	}
	return (1);
}

int		blt_print_flag(char **cmd)
{
	t_env	*tmp;

	tmp = g_env;
	while (tmp)
	{
		if (((*cmd == NULL || !ft_strncmp(*cmd, tmp->name, ft_strlen(*cmd))) &&\
					(tmp->type == EXPORT || tmp->type == ENV)))
		{
			ft_putstr("export ");
			ft_putstr(tmp->name);
			ft_putstr("=");
			ft_putendl(tmp->value);
			if (*cmd && *(cmd + 1) == NULL)
				break ;
			if (*cmd)
				cmd++;
		}
		tmp = tmp->next;
	}
	return (1);
}

int		blt_change_type(char *name, t_type type)
{
	t_env		*tmp;

	tmp = g_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			tmp->type = type;
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}
