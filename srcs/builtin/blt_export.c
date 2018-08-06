/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:38:16 by xmazella          #+#    #+#             */
/*   Updated: 2018/08/06 18:21:36 by xmazella         ###   ########.fr       */
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
					(tmp->type == EXPORT || tmp->type == ENV) ))
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

int		blt_flag_export(char **cmd)
{
	int		i;

	i = 0;
	if (ft_strcmp(cmd[i], "-p"))
		return (blt_export_error(cmd[i], 0));
	else
		return (blt_print_flag(cmd + 1));
}

int		blt_print_export(void)
{
	t_env *tmp;

	tmp = g_env;
	while (tmp)
	{	
		if (tmp->type == ENV || tmp->type == EXPORT)
		{
			ft_putstr(tmp->name);
			ft_putstr("=");
			ft_putendl(tmp->value);
		}
		tmp = tmp->next;
	}
	return (1);
}

int			blt_export_env(char **cmd)
{
			ft_putstr("coucou           1\n");
	while (*cmd)
	{
			ft_putstr("coucou           2\n");
		if (ft_strchr(*cmd, '=') == NULL)
		{
			ft_putstr("coucou           3\n");
		//	blt_setenv(cmd, &g_env, ENV);
			blt_setenv(cmd, &g_env, EXPORT);
		}
		else
			blt_setenv(cmd, &g_env, ENV);
		cmd++;
	}
	return (1);
}

int			blt_export(char **cmd)
{
	int		i;

	i = 0;
	if (cmd[i] == NULL)
		return (blt_print_export());
	if (cmd[i][0] == '-')
		return (blt_flag_export(cmd));
	else
		return (blt_export_env(cmd));
}
