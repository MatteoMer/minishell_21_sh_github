/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:14:08 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/11 06:03:48 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env		*blt_getenv(char *name, t_env *env)
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

static void			blt_setenv2(char **cmd, char *str, t_env **env, t_type type)
{
	t_env 	*tmp;

	tmp = (t_env *)malloc(sizeof(t_env));
	tmp->name = ft_strsub(*cmd, 0, str - (*cmd));
	tmp->value = ft_strdup(str + 1);
	tmp->type = type;
	blt_add_maillon(env, tmp);
}

int					blt_setenv(char **cmd, t_env **env, t_type type, int i)
{
	t_env	*tmp;
	char	*str;

	if (*cmd == NULL)
		ft_putendl("21sh: usage: setenv [ARG1] [ARG2]... [ARGN]");
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
			tmp->type = type;
		}
		else if (++i)
			blt_setenv2(cmd, str, env, type);
		cmd++;
	}
	return (i);
}
