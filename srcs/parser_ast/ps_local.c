/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_local.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:38:40 by xmazella          #+#    #+#             */
/*   Updated: 2018/08/01 17:36:26 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int			ps_check_loc(char *str)
{
	if (!ft_strchr(str, '='))
		return (0);
	return (1);
}

int			ps_parse_local(char **cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (ps_check_loc(*cmd) == 0)
			return (i);	
		blt_setenv(cmd, &g_loc, 1);
		ft_putstr("coucou\n");
		i++;
	}
	return (i);
}
