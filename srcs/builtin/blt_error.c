/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:48:53 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/14 06:39:36 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		blt_cd_error(int i, char *str)
{
	if (i == 1)
		ft_putendl("minishell: cd: HOME not set");
	if (i == 2)
	{
		ft_putstr("minishell: cd: ");
		if (str)
		{
			str[ft_strlen(str) - 1] = '\0';
			ft_putstr(ft_strrchr(str, '/') + 1);
			ft_putstr(": ");
		}
		ft_putendl("No such file or directory");
		free(str);
	}
	if (i == 3)
		ft_putendl("minishell: cd: OLDPWD not set");
	return (-1);
}

int		blt_env_error(char **cmd, int i)
{
	if (i == 1)
	{
		ft_putstr("minishell: ");
		ft_putstr(*cmd);
		ft_putstr(": ");
		ft_putstr("invalid argument\n");
	}
	return (0);
}

int		blt_error(char **cmd, int i)
{
	char	*str;

	str = (i == 1) ? "setenv" : "unsetenv";
	if (!cmd[0])
	{
		ft_putstr("minishell: ");
		ft_putstr(str);
		ft_putstr(": ");
		ft_putstr("need argument\n");
		return (1);
	}
	if (cmd[0] && cmd[1])
	{
		ft_putstr("minishell: ");
		ft_putstr(str);
		ft_putstr(": ");
		ft_putstr("how many arguments\n");
		return (2);
	}
	return (0);
}
