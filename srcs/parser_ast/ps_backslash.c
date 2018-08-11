/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_backslash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 19:16:33 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/11 07:24:40 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int					ps_backslash(t_list **tokens)
{
	t_list		*tmp;
	char		*str;

	tmp = *tokens;
	while (tmp)
	{
		if (tmp->content_size == 3)
			ps_do_parse_backslash(tmp->content);
		tmp = tmp->next;
	}
}
