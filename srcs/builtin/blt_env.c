/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 14:06:07 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/02 21:11:29 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int					blt_execve(char *path, char **cmd, t_env *env)
{
	pid_t	father;
	int		status;

	status = 0;
	father = fork();
	if (father > 0)
		waitpid(father, &status, 0);
	if (father == 0)
		execve(path, cmd, blt_conv_tab(env));
	free(path);
	return (status);
}

static int			blt_exec_cmd_env(char *str, t_env *env, char **cmd)
{
	char	**cpath;
	char	*tmp;
	char	**ptr;
	int		ret;
	int		i;

	i = 0;
	cpath = NULL;
	ret = blt_env_check(cmd);
	if (ret == 0)
	{
		if ((cpath = blt_getpath(env)) == NULL)
			return (0);
		ptr = cpath;
		tmp = blt_env_access(cmd, str, cpath, env);
		if (!tmp)
		{
			ft_putstr("minishell: env: No such file or directory: ");
			ft_putendl(str);
			return (-1);
		}
	}
	return (0);
}

static int			blt_exec_full_path(char *str, t_env *env, char **cmd)
{
	char *cpath;

	cpath = NULL;
	cpath = ft_strdup(str);
	if (access(cpath, F_OK) == 0)
		blt_execve(cpath, cmd, env);
	else
	{
		ft_putstr("minishell: env: No such file or directory: ");
		ft_putendl(str);
	}
	free(cpath);
	return (0);
}

static int			blt_exec_env(t_env *env, char **cmd)
{
	if (*cmd)
	{
		if (ft_strchr(*cmd, '/'))
			blt_exec_full_path(*cmd, env, cmd);
		else
			blt_exec_cmd_env(*cmd, env, cmd);
		return (1);
	}
	return (0);
}

int					blt_env(char **cmd)
{
	t_env	*ptr;
	t_env	*env;

	if (cmd[0] && ft_strcmp(cmd[0], "-i") == 0)
	{
		env = NULL;
		cmd++;
	}
	else
		env = blt_list_clone(g_env);
	cmd += !cmd[0] ? 0 : blt_setenv(cmd, &env, 0);
	ptr = env;
	if (blt_exec_env(env, cmd) == 0)
	{
		while (env)
		{
			if (env->type == 2)
			{
				ft_putstr(env->name);
				ft_putchar('=');
				ft_putendl(env->value);
			}
			env = env->next;
		}
	}
	blt_free_env(&ptr);
	return (2);
}
