/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 12:56:23 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 16:42:56 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	blt_echo(char **cmb)
{
	int		i;

	i = 0;
	while (cmb[i])
	{
		ft_putstr(cmb[i]);
		if (cmb[i + 1])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (1);
}

static void	blt_exit(char **cmd)
{
	if (*cmd != NULL && ft_atoi(*cmd) >= 0 && ft_atoi(*cmd) <= 255)
		return(exit(ft_atoi(*cmd)));
	return (exit(0));
}

int			blt_check(char **cmd)
{
	if (ft_strcmp(*cmd, "echo") == 0)
		return (blt_echo(cmd + 1));
	if (!ft_strcmp(*cmd, "cd"))
		return (blt_cd(cmd + 1));
	if (ft_strcmp(*cmd, "env") == 0)
		return (blt_env(cmd + 1));
	if (ft_strcmp(*cmd, "setenv") == 0)
		return (blt_setenv(cmd + 1, &(g_env), ENV) + 1);
	if (ft_strcmp(*cmd, "unsetenv") == 0)
		return (blt_unsetenv(cmd + 1));
	if (ft_strcmp(*cmd, "unset") == 0)
		return (blt_unset(cmd + 1));
	if (ft_strcmp(*cmd, "export") == 0)
		return (blt_export(cmd + 1));
	if (ft_strcmp(*cmd, "read") == 0)
		return (blt_read(cmd + 1));
	if (ft_strcmp(*cmd, "exit") == 0)
		blt_exit(cmd + 1);
	return (0);
}
