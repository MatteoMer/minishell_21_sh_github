/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 00:20:48 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/11 14:07:23 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env		*env_init_empty(void)
{
	t_env		*env;
	char		pwd[PATH_MAX + 1];

	if ((env = env_new_node()) == NULL)
		return (NULL);
	env->name = ft_strdup("PWD");
	getcwd(pwd, PATH_MAX);
	env->value = ft_strdup(pwd);
	if (!env->name || !env->value)
		return (NULL);
	return (env);
}

t_env		*env_init(char **environ)
{
	t_env		*env;
	char		**tmp;

	tmp = environ;
	if (!environ[0])
		env = env_init_empty();
	else
		env = env_parse_tab(tmp);
	return (env);
}

t_env		*env_parse_tab(char **environ)
{
	t_env		*env;
	t_env		*tmp;
	int			i;
	int			j;
	int			len;

	i = -1;
	j = -1;
	env = NULL;
	while (environ[++i])
	{
		if ((tmp = env_new_node()) == NULL)
			return (NULL);
		if ((len = ft_strclen(environ[i], '=')) == -1)
			break ;
		tmp->name = ft_strnew(len);
		ft_strncpy(tmp->name, environ[i], len);
		tmp->value = ft_strdup((environ[i] + len + 1));
		tmp->next = env;
		env = tmp;
	}
	return (env);
}

t_env		*env_new_node(void)
{
	t_env		*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->next = NULL;
	env->name = NULL;
	env->value = NULL;
	return (env);
}
