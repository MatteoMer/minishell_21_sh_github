/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:10:28 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/23 17:23:51 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int					main(int argc, char **argv, char **env)
{
	char		*buf;
	t_ps_tree	*ast;
	t_ps_tree	*tmp;
	t_term		term;

	g_env = env_init(env);
	term_init(&term);
	while (1)
	{
		buf = term_main_loop(&term);
		if (buf == NULL)
		{
			write(2, "Bye...\n", 7);
			return (-1);
		}
		ast = ps_main(buf); // lexer-parser-ast done
		tmp = ast;
		bn_rec(ast, 0);
		ps_free_ast(&ast);
		}

	return (0);
}
