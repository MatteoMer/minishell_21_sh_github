/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_env2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:23:18 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/29 12:00:03 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		blt_add_maillon(t_env **alst, t_env *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

t_env		*blt_list_clone(t_env *env)
{
	t_env *out;
	t_env *new;
	t_env *tmp;

	out = NULL;
	tmp = env;
	while (tmp)
	{
		new = (t_env *)malloc(sizeof(t_env));
		new->name = ft_strdup(tmp->name);
		new->value = ft_strdup(tmp->value);
		blt_add_maillon(&out, new);
		tmp = tmp->next;
	}
	return (out);
}

char		**blt_getpath(t_env *env)
{
	char *str;
	char **blt_tab;

	str = NULL;
	while (env)
	{
		if (ft_strcmp(env->name, "PATH") == 0)
		{
			str = env->value;
			break ;
		}
		env = env->next;
	}
	if (!str)
		return (NULL);
	blt_tab = ft_strsplit(str, ':');
	if (!blt_tab)
		return (NULL);
	return (blt_tab);
}

char		*blt_env_access(char **cmd, char *str, char **path, t_env *env)
{
	char		*tmp;
	char		**ptr;

	ptr = path;
	while (*path != NULL)
	{
		tmp = ft_strjoinf(*path++, "/");
		tmp = ft_strjoinf(tmp, str);
		if (access(tmp, F_OK) == 0)
		{
			blt_execve(tmp, cmd, env);
			break ;
		}
		ft_strdel(&tmp);
		if (*(path + 1) == NULL)
			return (NULL);
	}
	free(ptr);
	return (tmp);
}

char		**blt_conv_tab(t_env *env)
{
	char	**env_tab;
	char	*tmp_n;
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp && ++i)
		tmp = tmp->next;
	tmp = env;
	if (!(env_tab = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	i = 0;
	while (tmp)
	{
		tmp_n = ft_strdup(tmp->name);
		tmp_n = ft_strjoinf(tmp_n, "=");
		env_tab[i] = ft_strjoinf(tmp_n, tmp->value);
		tmp = tmp->next;
		i++;
	}
	env_tab[i] = NULL;
	return (env_tab);
}
