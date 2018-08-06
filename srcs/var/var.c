/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:58:56 by xmazella          #+#    #+#             */
/*   Updated: 2018/08/05 19:02:46 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "parse.h"

void			add_varloc(char *str)
{
	char 		**split;
	char		*string;
	
	split = (char **)malloc(sizeof(char *) * 2);
	split[0] = ft_strdup(str);
	split[1] = 0;
	string = split[0];
	if ((string = ft_strchr(split[0], '=')) == NULL)
		return ;
	*string = 0;
	if (blt_getenv(split[0], g_env) == NULL)
	{
		*string = '=';
		blt_setenv(split, &g_env, LOCALE);
	}
	else
	{
		*string = '=';
		blt_setenv(split, &g_env, ENV);
	}
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
