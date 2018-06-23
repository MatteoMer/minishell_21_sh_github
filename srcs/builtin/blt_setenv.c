/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:14:08 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/23 14:39:26 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static t_env		*blt_getenv(char *name, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static void			blt_setenv2(t_env *tmp, char **cmd, char *str, t_env **env)
{
	tmp = (t_env *)malloc(sizeof(t_env));
	tmp->name = ft_strsub(*cmd, 0, str - (*cmd));
	tmp->value = ft_strdup(str + 1);
	blt_add_maillon(env, tmp);
}

int					blt_setenv(char **cmd, t_env **env, int i)
{
	t_env	*tmp;
	char	*str;

	if (*cmd == NULL)
		ft_putendl("minishell: usage: setenv [ARG1] [ARG2]... [ARGN]");
	while (*cmd != NULL)
	{
		if (*cmd[0] == '=')
			return (blt_env_error(cmd, 1));
		if ((str = ft_strchr(*cmd, '=')) == NULL)
			return (i);
		*str = 0;
		if ((tmp = blt_getenv(*cmd, *env)) != NULL)
		{
			free(tmp->value);
			tmp->value = ft_strdup(str + 1);
			i++;
		}
		else if (i++ != -42)
			blt_setenv2(tmp, cmd, str, env);
		cmd++;
	}
	return (i);
}
