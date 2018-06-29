/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:10:28 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/29 14:00:31 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				unused(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

int					main(int argc, char **argv, char **env)
{
	char		*buf;
	t_ps_tree	*ast;
	t_ps_tree	*tmp;
	t_term		term;

	unused(argc, argv);
	g_env = env_init(env);
	if (term_init(&term) == -1)
		return (-1);
	sig_handler();
	while (1)
	{
		g_pid = 0;
		buf = term_main_loop(&term);
		if (buf == NULL)
		{
			write(2, "Bye...\n", 7);
			return (-1);
		}
		ast = ps_main(buf);
		tmp = ast;
		bn_rec(ast, 0);
		ps_free_ast(&ast);
	}
	return (0);
}
