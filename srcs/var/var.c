/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:58:56 by xmazella          #+#    #+#             */
/*   Updated: 2018/08/05 18:01:46 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			add_varloc(char *str)
{
	char 		**split;
	
	split = (char **)malloc(sizeof(char *) * 2);
	split[0] = ft_strdup(str);
	split[1] = 0;
	blt_setenv(split, &g_env, 0);
	ft_deltab(&split);
}

t_list			*set_varloc(t_list *lst)
{
	while (lst)
	{
		if ((lst->content_size != 3) || (!ft_strchr(lst->content, '=')))
			return (lst);
		add_varloc(lst->content);
		lst = lst->next;
	}
	return (lst);
}
