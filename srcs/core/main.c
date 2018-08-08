/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:10:28 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/08 18:06:08 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void				unused(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

static char				*get_buffer(t_term *term)
{
	char		*tmp;
	char		*buf;

	term_exec_tc("cr");
	term_exec_tc("cd");
	tmp = term_main_loop(term);
	if (tmp == NULL)
		exit(1);
	buf = ft_strtrim(tmp);
	return (buf);
}

int						main(int argc, char **argv, char **env)
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
		g_glob.g_pid = 0;
		buf = get_buffer(&term);
		ft_putchar('\n');
		ast = ps_main(buf);
		tmp = ast;
		bn_rec(ast, 0);
		ps_free_ast(&ast);
		free(buf);
	}
	return (0);
}
