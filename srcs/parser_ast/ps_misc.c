/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:10:24 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/25 00:43:09 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_ps_tree			*ps_init_tree(void)
{
	t_ps_tree	*new;

	if (!(new = (t_ps_tree *)malloc(sizeof(t_ps_tree))))
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->op_number = 0;
	return (new);
}

int					ps_error(char c)
{
	if (c == 5)
		ft_putstr("\033[31mREDIR ERROR\n\033[0m");
	else
	{
		ft_putstr("minishell: syntax error near unexcepted token: `");
		if (c == 125)
			ft_putstr("||");
		else if (c == 39)
			ft_putstr("&&");
		else
			ft_putchar(c);
		ft_putchar('\'');
		ft_putchar('\n');
	}
	return (-1);
}

void				ps_free_ast(t_ps_tree **ast)
{
	if (!(*ast))
		return ;
	ps_free_ast(&((*ast)->right));
	if (((*ast)->op_number) == 0 && (*ast)->content)
		ft_lstdel(&(*ast)->content, &ft_delfunction);
	ps_free_ast(&((*ast)->left));
	free(*ast);
}

t_list				*ps_check_content(t_list *tokens)
{
	t_list		*tmp;

	tmp = NULL;
	tmp = ft_lstreverse(tokens);
	if (!(tmp->content) || ((char *)tmp->content)[0] == '\0')
		return (tmp->next);
	else
		return (tmp);
}
