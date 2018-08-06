/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:21:03 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/05 21:29:35 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		free_it_pls(t_env *tmp)
{
	tmp->type = EXPORT;
}

int				blt_unsetenv(char **cmd)
{
	t_env	*tmp;

	tmp = g_env;
	if (blt_error(cmd, 0) != 0)
		return (1);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, *cmd) == 0)
		{
			free_it_pls(tmp);
			return (2);
		}
		tmp = tmp->next;
	}
	return (1);
}
