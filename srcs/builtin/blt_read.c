/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:24:31 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/19 13:42:33 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				option_read(char **cmd)
{
	char		*line;
	char		**set;
	char		**args;
	int			i;

	i = 0;
	get_next_line(0, &line);
	args = ft_strsplit(line, ' ');
	while (*cmd)
	{
		set = (char **)malloc(sizeof(char *) * 2);
		set[0] = ft_strjoin(*cmd, "=");
		if (args[i])
			set[0] = ft_strjoinf(set[0], args[i]);
		else
			set[0] = ft_strjoinf(set[0], "");
		set[1] = NULL;
		blt_setenv(set, &g_env, 0);
		cmd++;
		i++;
		ft_deltab(&set);
	}
	ft_strdel(&line);
	ft_deltab(&args);
}

char				*get_line(void)
{
	char		buf;
	char		line[LINE_MAX];
	int			stop;
	int			bs;
	int			i;

	i = 0;
	stop = 0;
	bs = 0;
	while (stop == 0)
	{
		read(0, &buf, 1);
		if (buf == '\\')
			bs = 1;
		else
			bs = 0;
		if (bs == 0 && buf == '\n')
			stop = 1;
		if (!bs)
			line[i] = buf;
		i++;
	}
	line[i - 1] = 0;
	return (ft_strdup(line));
}

void				basic_read(char **cmd)
{
	char			*line;

	line = get_line();
	ft_putendl("here");
	ft_putendl("");
	ft_putendl("");
	ft_putendl("");
	ft_putendl(line);
	(void)cmd;
}

int					blt_read(char **cmd)
{
	pid_t			pid;

	if (*cmd == NULL)
	{
		get_next_line(0, NULL);
		return (0);
	}
	pid = fork();
	if (pid == 0)
	{
		if (!ft_strcmp(*cmd, "-r"))
			option_read(cmd + 1);
		else
			basic_read(cmd);
		exit(0);
	}
	if (waitpid(pid, 0, 0) < 0)
		return (-1);
	return (1);
}
