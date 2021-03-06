/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:49:59 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 18:10:46 by mmervoye         ###   ########.fr       */
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
		if ((tmp_n = ft_strdup(tmp->name)) == NULL)
			malloc_error();
		if ((tmp_n = ft_strjoinf(tmp_n, "=")) == NULL)
			malloc_error();
		if ((env_tab[++i] = ft_strjoinf(tmp_n, tmp->value)) == NULL)
			malloc_error();
		tmp = tmp->next;
	}
	return (env_tab);
}
