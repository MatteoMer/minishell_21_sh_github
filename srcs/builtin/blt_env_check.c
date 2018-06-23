/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_env_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:28:38 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/22 18:56:35 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			blt_env_check(char **cmd)
{
	int i;

	i = 0;
	if (!(*cmd))
		return (0);
	while (cmd[i] && ft_strcmp(cmd[i], "=") == 0)
		i++;
	if (cmd[i])
	{
		if (!ft_strcmp(cmd[i], "echo"))
			return (1);
		if (!ft_strcmp(cmd[i], "cd"))
			return (1);
		if (!ft_strcmp(cmd[i], "setenv"))
			return (1);
		if (!ft_strcmp(cmd[i], "unsetenv"))
			return (1);
		if (!ft_strcmp(cmd[i], "exit"))
			exit(0);
	}
	return (0);
}
