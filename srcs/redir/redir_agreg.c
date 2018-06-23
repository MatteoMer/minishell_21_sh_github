/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_agreg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:24:28 by mmervoye          #+#    #+#             */
/*   Updated: 2018/05/17 17:41:46 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				redir_agreg_check(t_list **tokens, char *buf)
{
	int		len;
	int		i;
	t_list	*new;

	if (*buf != '&')
		return (0);
	len = 0;
	i = 1;
	new = ft_lstnew(NULL, 0);
	len++;
	new->content_size = 9;
	if (ft_isdigit(buf[i]) || buf[i] == '-')
	{
		len++;
		new->content_size = 10;
		new->content = ft_strnew(2);
		((char *)new->content)[0] = buf[i];
		((char *)new->content)[1] = '\0';
	}
	ft_lstadd(tokens, new);
	return (len);
}
