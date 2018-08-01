/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_set_locale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 21:37:28 by xmazella          #+#    #+#             */
/*   Updated: 2018/08/01 21:57:28 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				bn_set_locale(char **cmd)
{
	char	*ptr;
	int		i;

	i = 0;
	while (*cmd)
	{
		if (!(ptr = ft_strchr(*cmd, '=')))
			return (i);
		else
			blt_setenv(cmd ,g_env, 0, LOC);
		i++;
	}
	return (i);
}
