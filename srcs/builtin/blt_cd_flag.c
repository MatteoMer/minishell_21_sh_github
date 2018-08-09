/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_cd_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:13:47 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 16:40:48 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		blt_cd_check_error(char *str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'P' && str[i] != 'L')
			return (-1);
		i++;
	}
	return (0);
}

int		blt_cd_flag(char **cmd, int *index)
{
	int i;
	int j;
	int tmp;

	j = 0;
	i = 1;
	tmp = 0;
	if (!cmd[j])
		return (1);
	while (cmd[j] && cmd[j][0] == '-')
	{
		if (cmd[j][1] == '\0' || cmd[j][1] == '-')
			break ;
		if (blt_cd_check_error(cmd[j]) == -1)
			return (tmp);
		else
			*index = j + 1;
		while (cmd[j][i++])
			tmp = cmd[j][i - 1];
		i = 1;
		j++;
	}
	return (tmp == 1 ? 'L' : 'P');
}
