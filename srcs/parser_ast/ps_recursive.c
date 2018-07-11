/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:55:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/08 11:32:18 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int					ps_launch_recursive(t_ps_tree **ast, t_list **tokens,\
t_list **ptr, t_list **prev)
{
	(*ast)->op_number = (*tokens)->content_size;
	if (!(*prev))
		*ptr = NULL;
	else
		(*prev)->next = NULL;
	(*ast)->left = ps_recursive(&(*tokens)->next);
	(*ast)->right = ps_recursive(ptr);
	ft_lstdelone(tokens, &ft_delfunction);
	return (1);
}

int					ps_do_recursive_1(t_ps_tree **ast, t_list **tokens)
{
	t_list		*prev;
	t_list		*ptr;

	prev = NULL;
	ptr = *tokens;
	while (*tokens)
	{
		if ((*tokens)->content_size == ';')
			return (ps_launch_recursive(ast, tokens, &ptr, &prev));
		prev = *tokens;
		*tokens = (*tokens)->next;
	}
	*tokens = ptr;
	return (0);
}

int					ps_do_recursive_2(t_ps_tree **ast, t_list **tokens)
{
	t_list		*prev;
	t_list		*ptr;

	prev = NULL;
	ptr = *tokens;
	while (*tokens)
	{
		if ((*tokens)->content_size == 39 || (*tokens)->content_size == 125)
			return (ps_launch_recursive(ast, tokens, &ptr, &prev));
		prev = *tokens;
		*tokens = (*tokens)->next;
	}
	*tokens = ptr;
	return (0);
}

int					ps_do_recursive_3(t_ps_tree **ast, t_list **tokens)
{
	t_list		*prev;
	t_list		*ptr;

	prev = NULL;
	ptr = *tokens;
	while (*tokens)
	{
		if ((*tokens)->content_size == '|')
			return (ps_launch_recursive(ast, tokens, &ptr, &prev));
		prev = *tokens;
		*tokens = (*tokens)->next;
	}
	*tokens = ptr;
	return (0);
}

t_ps_tree			*ps_recursive(t_list **tokens)
{
	int			found;
	t_ps_tree	*new;

	if (!(*tokens))
		return (NULL);
	if (!(new = ps_init_tree()))
		return (NULL);
	found = ps_do_recursive_1(&new, tokens);
	if (!found)
	{
		found = ps_do_recursive_2(&new, tokens);
		if (!found)
		{
			found = ps_do_recursive_3(&new, tokens);
			if (!found)
				new->content = ps_check_content(*tokens);
		}
	}
	return (new);
}
