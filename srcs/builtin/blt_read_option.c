/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_read_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:41:25 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/11 07:22:29 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int					blt_read_r(char **cmd)
{
	char		*line;
	char		*str;
	char		**split;
	int			i;

	i = 0;
	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	while (*cmd && split[i])
	{
		str = ft_strjoin(*cmd, "=");
		str = ft_strjoinf(str, split[i]);
		add_varloc(str, LOCALE);
		ft_strdel(&str);
		cmd++;
		i++;
	}
	ft_deltab(&split);
	ft_strdel(&line);
	return (0);
}

int					blt_read_option(char **cmd)
{
	if (ft_strcmp(*cmd, "-r"))
		ft_putendl("21sh: read: usage: read [-r] var1 ... varN");
	else
		blt_read_r(cmd + 1);
	return (0);
}
