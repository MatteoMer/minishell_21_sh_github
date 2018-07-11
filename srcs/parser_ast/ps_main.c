/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:41:16 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/09 18:20:46 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_ps_tree			*ps_main(char *buf)
{
	t_ps_tree	*ast;
	t_list		*tokens;
	t_list		*tmp;

	ast = NULL;
	tokens = NULL;
	tokens = lx_main(buf);
	if (!tokens)
		return (NULL);
	tmp = tokens;
	if (ps_do_parse(tokens) == -1)
		return (NULL);
	if ((ast = ps_recursive(&tokens)) == 0)
		return (NULL);
	return (ast);
}
