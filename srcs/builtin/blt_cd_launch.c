/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_cd_launch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:35:34 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 18:03:40 by mmervoye         ###   ########.fr       */
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
		if ((path = ft_strdup(env_get("HOME"))) == NULL)
			malloc_error();
		ret = blt_cd_launch(path, flags == 'P' ? 1 : 0);
		free(path);
		return (ret);
	}
	else
	{
		if (env_get("OLDPWD") == NULL)
			return (blt_cd_error(3, NULL));
		if ((path = ft_strdup(env_get("OLDPWD"))) == NULL)
			malloc_error();
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
	if ((cmd[0] = ft_strdup("OLDPWD=")) == NULL)
		malloc_error();
	if ((cmd[0] = ft_strjoinf(cmd[0], pwd)) == NULL)
		malloc_error();
	cmd[1] = 0;
	blt_setenv(cmd, &g_env, ENV);
	free(cmd[0]);
	if ((cmd[0] = ft_strdup("PWD=")) == NULL)
		malloc_error();
	chdir(path);
	if (nb)
	{
		getcwd(pwd, MAXPATHLEN);
		if ((cmd[0] = ft_strjoinf(cmd[0], pwd)) == NULL)
			malloc_error();
		blt_setenv(cmd, &g_env, ENV);
	}
	else
	{
		getcwd(pwd, MAXPATHLEN);
		if ((cmd[0] = ft_strjoinf(cmd[0], path)) == NULL)
			malloc_error();
		blt_setenv(cmd, &g_env, ENV);
	}
	free(cmd[0]);
	return (1);
}
