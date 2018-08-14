/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_wrapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:42:37 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/14 04:21:49 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int			check_redir(t_list *lst)
{
	t_list		*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->content_size != 3)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int					bn_wrap_exec(char **bn_tab, char **cpath,\
	char **cmd_bn_tab, t_ps_tree *tree)
{
	int		ret;

	if (check_redir(tree->content) == 0)
	{
		ret = redir_exec(bn_tab, cpath, cmd_bn_tab, tree);
		ft_deltab(&cmd_bn_tab);
	}
	else
		ret = bn_func_exec(bn_tab, cpath, cmd_bn_tab);
	return (ret);
}

int					bn_wrap_blt(char **cmd, t_ps_tree *tree)
{
	int		ret;

	if (check_redir(tree->content) == 0)
		ret = redir_blt_exec(cmd, tree);
	else
		ret = blt_check(cmd);
	return (ret);
}
