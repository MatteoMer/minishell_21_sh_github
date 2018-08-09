/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_exec_blt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:50:44 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 16:52:38 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int						fork_exec_blt(char **cmd)
{
	pid_t			pid;
	int				ret;

	if ((pid = fork()) == -1)
		return (-1);
	if (pid == 0)
	{
		blt_check(cmd);
		exit(0);
	}
	if (waitpid(pid, &ret, 0) < 0)
		return (-1);
	return (ret);
}
