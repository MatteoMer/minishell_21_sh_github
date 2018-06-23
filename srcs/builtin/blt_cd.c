/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:57:58 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/23 14:47:59 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*blt_cd_check_cdpath(char *str)
{
	char	*cpath;

	cpath = NULL;
	cpath = ft_strjoin(env_get("CDPATH"), "/");
	cpath = ft_strjoinf(cpath, str);
	if (access(cpath, F_OK) != 0)
	{
		free(cpath);
		return (str);
	}
	else
		return (cpath);
}

static char		*blt_cd_normalize_path(char *s)
{
	return ((s[ft_strlen(s) - 1] == '/' ? ft_strdup(s) : ft_strjoin(s, "/")));
}

static char		*blt_cd_set_curpath(char *s)
{
	char *pwd;
	char *tmp;

	if ((env_get("PWD")) == NULL)
	{
		ft_putendl("21sh: error: PWD is not set.");
		return (NULL);
	}
	pwd = env_get("PWD");
	if (*s != '/')
	{
		pwd = blt_cd_normalize_path(pwd);
		tmp = s;
		s = ft_strjoinf(pwd, s);
		free(tmp);
	}
	tmp = s;
	s = blt_cd_normalize_path(s);
	free(tmp);
	return (s);
}

static int		blt_cd_execve_opt(char *cpath, int i)
{
	char	*tmp;

	if (i == 0)
	{
		cpath = blt_cd_set_curpath(cpath);
		if (!cpath)
			return (-1);
		tmp = cpath;
		cpath = blt_cd_normalize(cpath);
		free(tmp);
		if (access(cpath, F_OK) != 0)
			return (blt_cd_error(2, cpath));
		blt_cd_launch(cpath, 0);
	}
	else
	{
		if (access(cpath, F_OK) != 0)
			return (blt_cd_error(2, cpath));
		blt_cd_launch(cpath, 1);
	}
	free(cpath);
	return (1);
}

int				blt_cd(char **cmd)
{
	int		flags;
	int		index;
	char	*cpath;

	cpath = NULL;
	index = 0;
	flags = blt_cd_flag(cmd, &index);
	if (flags == -1 && (env_get("HOME") == 0))
		return (blt_cd_error(1, NULL));
	if (cmd[index] == 0 || (cmd[index][0] == '-' && !cmd[index][1]))
		return (blt_cd_launch_sp(flags, cmd[index] == 0 ? 0 : 1));
	if (cmd[index] && cmd[index][0] == '/')
		cpath = ft_strdup(cmd[index]);
	else if (cmd[index] && cmd[index][0] == '.')
		cpath = blt_cd_normalize_path(cmd[index]);
	else if ((env_get("CDPATH") && cmd[index]))
		cpath = blt_cd_check_cdpath(cmd[index]);
	else if (cmd[index])
		cpath = blt_cd_normalize_path(cmd[index]);
	if (flags != 'P')
		return (blt_cd_execve_opt(cpath, 0));
	else
		return (blt_cd_execve_opt(cpath, 1));
}
