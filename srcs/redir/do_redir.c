/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:49:22 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/15 01:30:27 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int					redir_blt_exec(char **cmd, t_ps_tree *tree)
{
	pid_t			c_pid;
	int				ret;

	if ((c_pid = fork()) == -1)
		return (-1);
	if (c_pid == 0)
	{
		do_redir(tree->content);
		exit(blt_check(cmd));
	}
	if (waitpid(c_pid, &ret, 0) < 0)
		return (-1);
	return (ret);
}

int					redir_exec(char **bn_tab, char **cpath,\
	char **cmd_bn_tab, t_ps_tree *tree)
{
	pid_t			c_pid;
	int				ret;

	if ((c_pid = fork()) == -1)
		return (-1);
	if (c_pid == 0)
	{
		do_redir(tree->content);
		bn_func_exec(bn_tab, cpath, cmd_bn_tab);
		exit(0);
	}
	if (waitpid(c_pid, &ret, 0) < 0)
		return (-1);
	return (ret);
}

int					exec_redir(t_list *lst, int io)
{
	int			to_redir;
	t_list		*next;

	to_redir = lst->content_size == 5 ? 0 : 1;
	if (io != -1)
		to_redir = io;
	next = lst->next;
	return (wrapper_redir(lst, to_redir, ((char *)next->content)));
}

int					do_redir(t_list *lst)
{
	t_list		*tmp;
	int			old;

	tmp = lst;
	old = -1;
	while (tmp)
	{
		if (tmp->content_size == 4)
			old = ((char *)tmp->content)[0] - 48;
		else if (tmp->content_size >= 5 && tmp->content_size <= 8)
		{
			if (exec_redir(tmp, old) == -1)
				return (-1);
			else
				tmp = tmp->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
