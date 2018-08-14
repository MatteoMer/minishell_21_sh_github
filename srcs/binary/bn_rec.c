/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 10:21:52 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/14 07:47:23 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int				bn_convert_count(t_list *tmp)
{
	int		i;

	i = 0;
	while (tmp)
	{
		if (tmp->content_size == 3)
			i++;
		else if (tmp->content_size != 4 && tmp->content_size != 10)
			tmp = tmp->next;
		tmp = tmp->next;
	}
	return (i);
}

static char				**bn_convert_list(t_list *lst)
{
	char		**env_tab;
	int			i;

	env_tab = NULL;
	if ((lst = set_varloc(lst)) == NULL)
		return (NULL);
	i = bn_convert_count(lst);
	if (!(env_tab = (char **)malloc(sizeof(char *) * i + 1)))
		malloc_error();
	env_tab[i] = NULL;
	i = 0;
	while (lst)
	{
		if (lst->content_size == 3)
		{
			env_tab[i] = ft_strdup(lst->content);
			i++;
		}
		else if (lst->content_size != 4 && lst->content_size != 10)
			lst = lst->next;
		lst = lst->next;
	}
	return (env_tab);
}

int						bn_execve1(char *path, char **bn_tab)
{
	pid_t	father;
	int		status;
	char	**env_tab;
	
	env_tab = NULL;
	father = fork();
	if (father < 0)
		return (-1);
	if (father > 0)
		wait(&status);
	else
	{
		g_loc.g_pid = father;
		env_tab = env_conv_tab();
		execve(path, bn_tab, env_tab);
//		ft_deltab(&env_tab); pas utile mais contestable
		exit(0);
	}
	return (status);
}

int						bn_func_exec(char **bn_tab, char **cpath,\
						char **cmd_bn_tab)
{
	int		j;
	int		ret;

	j = -1;
	ret = 0;
	while (bn_tab[++j])
	{
		*cpath = ft_strjoin(bn_tab[j], "/");
		*cpath = ft_strjoinf(*cpath, cmd_bn_tab[0]);
		if (access(*cpath, F_OK) == 0)
		{
			ret = bn_execve1(*cpath, cmd_bn_tab);
			free(*cpath);
			break ;
		}
		free(*cpath);
	}
	if (bn_tab[j] == NULL)
	{
		ft_putstr("21sh: ");
		ft_putstr(*cmd_bn_tab);
		ft_putendl(": command not found");
	}
	return (ret);
}

int						bn_binary(t_ps_tree *tree)
{
	char			**bn_tab;
	char			**cmd_bn_tab;
	char			*cpath;
	int				ret;

	ret = 0;
	bn_tab = NULL;
	cmd_bn_tab = NULL;
	if ((cmd_bn_tab = bn_convert_list(tree->content)) == NULL)
		return (0);
	if (*cmd_bn_tab && **cmd_bn_tab == '/' && access(cmd_bn_tab[0], F_OK) == 0)
		ret = bn_execve1(cmd_bn_tab[0], cmd_bn_tab);
	else if ((bn_wrap_blt(cmd_bn_tab, tree)) != 0)
		ret = 1;
	else if ((bn_tab = ft_sortpath(bn_tab, cmd_bn_tab)) != NULL)
	{
		ret = bn_wrap_exec(bn_tab, &cpath, cmd_bn_tab, tree);
		ft_deltab(&bn_tab);
	}
	else
		ft_putendl_fd("21sh: command not found", 2);
	ft_deltab(&cmd_bn_tab);
	return (ret);
}
