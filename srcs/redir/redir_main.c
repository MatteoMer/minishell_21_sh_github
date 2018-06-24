/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:56:44 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/25 00:42:24 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int			redir_input(char *name, int io)
{
	int		fd;
	int		to_change;

	to_change = io == -1 ? 0 : io;
	if ((fd = open(name, O_RDONLY)) == -1)
		return (-1);
	dup2(fd, to_change);
	close(fd);
	return (0);
}

static int			redir_heredoc(char *end_str, int io)
{
	int		fd;
	char	*line;
	char	*tmp;

	tmp = ft_strnew(1);
	fd = open(".heredoc_tmptmp", O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU | \
	S_IRWXG);
	if (fd == -1)
		ft_putendl("lololol");
	while (1)
	{
		ft_putstr("heredoc > ");
		get_next_line(0, &line);
		if (!ft_strcmp(line, end_str))
			break ;
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	return (redir_input(".heredoc_tmptmp", io));
}

static int			redir_out(char *name, int op, int io)
{
	int			fd;
	int			to_change;

	to_change = io == -1 ? 1 : io;
	if (op == 6)
	{
		fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP |\
				S_IWGRP | S_IWUSR);
	}
	else
	{
		fd = open(name, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP |\
				S_IWGRP | S_IWUSR);
	}
	if (fd == -1)
		return (-1);
	dup2(fd, to_change);
	close(fd);
	return (0);
}

void				redir_exec(int op, char *name, int io)
{
	if (op == 5)
	{
		if (redir_input(name, io) == -1)
		{
			ft_putstr("minishell: No such file or directory: ");
			ft_putendl(name);
			return ;
		}
	}
	if (op == 6 || op == 8)
		redir_out(name, op, io);
	if (op == 7)
		redir_heredoc(name, io);
}
