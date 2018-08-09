/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec42shrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 22:07:12 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 18:10:15 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				exec_42shrc(void)
{
	char		*home;
	char		*line;
	int			fd;
	t_ps_tree	*ast;

	home = getenv("HOME");
	if (!home)
		return ;
	if ((home = ft_strjoin(home, "/.config/42sh/.42shrc")) == NULL)
		malloc_error();
	if ((fd = open(home, O_RDONLY)) == -1)
		return ;
	ft_strdel(&home);
	while (get_next_line(fd, &line))
	{
		ast = ps_main(line);
		bn_rec(ast, 0);
		ps_free_ast(&ast);
		free(line);
	}
}
