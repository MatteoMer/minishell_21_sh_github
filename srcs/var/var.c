/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:58:56 by xmazella          #+#    #+#             */
/*   Updated: 2018/08/02 21:12:25 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			set_varloc(char **cmd)
{
	int		i;

	i = 0;
	while(cmd[i])
	{
		if (ft_strchr(cmd[i], '=') == NULL)
			return (i);
		blt_setenv(cmd, &g_env, 0);
		i++;
	}
	ft_putendl("ldldldld");
	return (i);
}
