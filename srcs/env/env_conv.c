/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:49:59 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/02 20:04:51 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char				**env_conv_tab(void)
{
	char		**env_tab;
	char		*tmp_n;
	t_env		*tmp;
	int			i;

	i = 0;
	tmp = g_env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = g_env;
	if (!(env_tab = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	env_tab[i - 1] = 0;
	i = -1;
	while (tmp->next)
	{
		tmp_n = ft_strdup(tmp->name);
		tmp_n = ft_strjoinf(tmp_n, "=");
		env_tab[++i] = ft_strjoinf(tmp_n, tmp->value);
		tmp = tmp->next;
	}
	return (env_tab);
}
