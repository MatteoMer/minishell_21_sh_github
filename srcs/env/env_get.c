/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:55:27 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/11 14:13:35 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char		*env_get(char *path)
{
	t_env		*tmp;

	tmp = g_env;
	while (tmp)
	{
		if (!ft_strcmp(path, tmp->name))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
