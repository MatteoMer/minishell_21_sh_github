/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_rec2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:35:34 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/26 13:39:59 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int					free_and_return(char ***ft_tab)
{
	ft_deltab(ft_tab);
	return (-1);
}

char				**ft_sortpath(char **bn_tab, char **cmd_bn_tab)
{
	if (env_get("PATH") == NULL)
	{
		ft_deltab(&cmd_bn_tab);
		return (NULL);
	}
	bn_tab = ft_strsplit(env_get("PATH"), ':');
	return (bn_tab);
}

void				exec_wrapper(t_ps_tree *tree)
{
	if (tree->op_number == '|')
		do_pipe(tree);
	else
		bn_binary(tree);
}

int					bn_rec(t_ps_tree *tree, char op)
{
	int		ret;

	if (!tree)
		return (0);
	if (tree->left != NULL)
		ret = bn_rec(tree->left, tree->op_number);
	if (tree->op_number != 0 && tree->op_number != '|')
	{
		if (ret == 0 && tree->op_number == '&' + 1)
			(tree->right != NULL) ? bn_rec(tree->right, tree->op_number) : 0;
		else if (ret != 0 && tree->op_number == '|' + 1)
			(tree->right != NULL) ? bn_rec(tree->right, tree->op_number) : 0;
		else if (tree->op_number == ';')
			bn_rec(tree->right, tree->op_number);
	}
	else if (op != '|')
		exec_wrapper(tree);
	return (0);
}
