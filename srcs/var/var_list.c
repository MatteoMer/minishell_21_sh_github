/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 17:25:02 by xmazella          #+#    #+#             */
/*   Updated: 2018/08/02 18:39:19 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_var	*create_list(char **env)
{
	t_var var;
	t_var tmp;

	var = NULL;
	i = -1;
	while (env[++i])
	{
		if ((len = ft_strclen(env[i], '=')) == -1)
			break;
		var_set(&tmp, env[i] - ft_strlen(env[i] - len), env[i] + len + 1);
		tmp->next = var;
		var = tmp;
	}
	return (var);
}
