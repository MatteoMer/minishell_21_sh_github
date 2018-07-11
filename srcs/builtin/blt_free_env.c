/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_free_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:58:14 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/11 13:26:31 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			blt_free_env(t_env **ptr)
{
	char		*str;
	t_env		*ptr_env;

	while (*ptr)
	{
		str = (*ptr)->value;
		ft_strdel(&str);
		str = (*ptr)->name;
		ft_strdel(&str);
		ptr_env = *ptr;
		*ptr = (*ptr)->next;
		free(ptr_env);
	}
}
