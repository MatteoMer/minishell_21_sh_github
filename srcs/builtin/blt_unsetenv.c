/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:21:03 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/11 07:18:18 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				blt_unsetenv(char **cmd)
{
	t_env *tmp;

	tmp = g_env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, *cmd) == 0)
		{
			tmp->type = LOCALE;
			break ;
		}
		tmp = tmp->next;
	}
	return (1);
}
