/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   blt_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:54:30 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/22 18:54:18 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		blt_cd_error(int i, char *str)
{
	if (i == 1)
		ft_putendl("21sh: cd: HOME not set");
	if (i == 2)
	{
		ft_putstr("21sh: cd: ");
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
		ft_putendl("21sh: cd: OLDPWD not set");
	return (-1);
}

int		blt_env_error(char **cmd, int i)
{
	if (i == 1)
	{
		ft_putstr("21sh: ");
		ft_putstr(*cmd);
		ft_putstr(": ");
		ft_putstr("invalid argument\n");
	}
	return (0);
}

int		blt_bn_error(char **cmd1, char **cmd, int i, int **ret)
{
	if (i == 1)
	{
		ft_putstr("21sh: ");
		ft_putstr(*cmd);
		ft_putstr(": command not found");
		ft_putstr("\n");
		ft_deltab(&cmd);
		ft_deltab(&cmd1);
		free(*ret);
	}
	return (-1);
}

int		blt_error(char **cmd, int i)
{
	char	*str;

	str = (i == 1) ? "setenv" : "unsetenv";
	if (!cmd[0])
	{
		ft_putstr("21sh: ");
		ft_putstr(str);
		ft_putstr(": ");
		ft_putstr("need argument\n");
		return (1);
	}
	if (cmd[0] && cmd[1])
	{
		ft_putstr("21sh: ");
		ft_putstr(str);
		ft_putstr(": ");
		ft_putstr("how many arguments\n");
		return (2);
	}
	return (0);
}
