/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 10:21:52 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/29 13:49:36 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int					bn_convert_count(t_list *tmp, int i)
{
	while (tmp)
	{
		if (tmp->content_size >= 4 && tmp->content_size <= 8)
		{
			if (tmp->next)
				tmp = tmp->next->next;
			else
				tmp = tmp->next;
		}
		i++;
		if (!tmp)
			break ;
		tmp = tmp->next;
	}
	return (i);
}

static char					**bn_convert_list(t_list *lst)
{
	char		**env_tab;
	int			i;

	i = bn_convert_count(lst, 0);
	env_tab = NULL;
	if (!(env_tab = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	env_tab[i] = NULL;
	i = 0;
	while (lst)
	{
		if (lst->content_size >= 4 && lst->content_size <= 8)
		{
			if (lst->next)
				lst = lst->next->next;
			else
				lst = lst->next;
		}
		if (!lst)
			break ;
		env_tab[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
	}
	return (env_tab);
}

int							bn_execve1(char *path, char **bn_tab, t_list *lst)
{
	pid_t	father;
	int		status;
	char	**env_tab;

	(void)lst;
	env_tab = NULL;
	father = fork();
	if (father > 0)
		wait(&status);
	if (father == 0)
	{
		g_pid = father;
		env_tab = env_conv_tab();
		execve(path, bn_tab, env_tab);
		ft_deltab(&env_tab);
		exit(0);
	}
	ft_deltab(&bn_tab);
	return (status);
}

static int					*bn_func_exec(char **bn_tab, char **cpath,\
		char **cmd_bn_tab, t_ps_tree *tree)
{
	int		j;
	int		*ret;

	ret = (int *)malloc(sizeof(int) * 3);
	ret[0] = 0;
	j = -1;
	while (bn_tab[++j])
	{
		*cpath = ft_strjoin(bn_tab[j], "/");
		*cpath = ft_strjoinf(*cpath, cmd_bn_tab[0]);
		if (access(*cpath, F_OK) == 0)
		{
			ret[0] = bn_execve1(*cpath, cmd_bn_tab, tree->content);
			free(*cpath);
			break ;
		}
		free(*cpath);
	}
	ret[1] = j;
	ret[2] = 0;
	return (ret);
}

int							bn_binary(t_ps_tree *tree)
{
	char			**bn_tab;
	char			**cmd_bn_tab;
	char			*cpath;
	int				i;
	int				*ret;

	i = -1;
	bn_tab = NULL;
	cmd_bn_tab = NULL;
	cmd_bn_tab = bn_convert_list(tree->content);
	if (access(cmd_bn_tab[0], F_OK) == 0)
		return (bn_execve1(cmd_bn_tab[0], cmd_bn_tab, tree->content));
	if ((blt_check(cmd_bn_tab)) != 0)
		return (free_and_return(&cmd_bn_tab));
	bn_tab = ft_sortpath(bn_tab, cmd_bn_tab);
	if (!bn_tab)
		return (-1);
	ret = bn_func_exec(bn_tab, &cpath, cmd_bn_tab, tree);
	if (bn_tab[ret[1]] == NULL)
		return (blt_bn_error(bn_tab, cmd_bn_tab, 1, &ret));
	ft_deltab(&bn_tab);
	i = ret[0];
	free(ret);
	return (i);
}
