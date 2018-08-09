/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:06:47 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/08 19:19:44 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char				**blt_read_parse(void)
{
	int			bs;
	char		*line;
	char		*buf;

	bs = 0;
	line = ft_strnew(1);
	while (1)
	{
		read(0, &buf, 1);
		if (buf[0] == '\\')
		{
			ft_putendl("coucou");
			bs = 1;
		}
		if (buf[0] == '\n' && bs == 0)
			break ;
		if ((line = ft_strjoinf(line, buf)) == NULL)
			return (NULL);
		if (bs && buf[0] != '\\')
			bs = 0;
	}
	return (NULL);
}

int					blt_do_read(char **cmd)
{
	char		**line;

	line = cmd;
	if ((line = blt_read_parse()) == NULL)
		return (-1);
	return (0);
}

int					blt_read(char **cmd)
{
	char		*tmp;

	if (*cmd && *cmd[0] == '-')
		blt_read_option(cmd);
	else if (*cmd)
	{
		if ((blt_do_read(cmd)) == -1)
			return (-1);
	}
	else
	{
		get_next_line(0, &tmp);
		free(tmp);
	}
	return (1);
}
