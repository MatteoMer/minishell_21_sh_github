/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:38:16 by xmazella          #+#    #+#             */
/*   Updated: 2018/08/08 17:20:24 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			blt_flag_export(char **cmd)
{
	int		i;

	i = 0;
	if (ft_strcmp(cmd[i], "-p"))
		return (blt_export_error(cmd[i], 0));
	else
		return (blt_print_flag(cmd + 1));
}

int			blt_print_export(void)
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
	t_env	*tmp;
	char	*str;

	while (*cmd != NULL)
	{
		if (ft_strchr(*cmd, '=') == NULL ||\
				(ft_strchr(*cmd, '=') && (*cmd)[ft_strlen(*cmd) - 1] == '='))
		{
			tmp = blt_getenv(*cmd, g_env);
			if (tmp == NULL)
			{
				if ((*cmd)[ft_strlen(*cmd) - 1] != '=')
					str = ft_strjoin(*cmd, "=");
				else
					str = ft_strdup(*cmd);
				add_varloc(str, EXPORT);
			}
			else
				blt_change_type(*cmd, ENV);
		}
		else
			add_varloc(*cmd, ENV);
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
