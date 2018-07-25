/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_cd_launch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:35:34 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/23 14:38:47 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		blt_cd_launch_sp(int flags, int n)
{
	char	*path;
	int		ret;

	if (n == 0)
	{
		if (env_get("HOME") == NULL)
			return (blt_cd_error(1, NULL));
		path = ft_strdup(env_get("HOME"));
		ret = blt_cd_launch(path, flags == 'P' ? 1 : 0);
		free(path);
		return (ret);
	}
	else
	{
		if (env_get("OLDPWD") == NULL)
			return (blt_cd_error(3, NULL));
		path = ft_strdup(env_get("OLDPWD"));
		ret = blt_cd_launch(path, flags == 'P' ? 1 : 0);
		free(path);
		return (ret);
	}
}

int		blt_cd_launch(char *path, int nb)
{
	char pwd[MAXPATHLEN];
	char *cmd[2];

	getcwd(pwd, MAXPATHLEN);
	cmd[0] = ft_strdup("OLDPWD=");
	cmd[0] = ft_strjoinf(cmd[0], pwd);
	cmd[1] = 0;
	blt_setenv(cmd, &g_env, 0);
	free(cmd[0]);
	cmd[0] = ft_strdup("PWD=");
	chdir(path);
	if (nb)
	{
		getcwd(pwd, MAXPATHLEN);
		cmd[0] = ft_strjoinf(cmd[0], pwd);
		blt_setenv(cmd, &g_env, 0);
	}
	else
	{
		getcwd(pwd, MAXPATHLEN);
		cmd[0] = ft_strjoinf(cmd[0], path);
		blt_setenv(cmd, &g_env, 0);
	}
	free(cmd[0]);
	return (1);
}