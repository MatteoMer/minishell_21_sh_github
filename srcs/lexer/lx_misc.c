/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:14:43 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/29 11:41:07 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int				lx_is_word(char buf)
{
	if (buf == ' ' || buf == '\t')
		return (0);
	if (buf == '&' || buf == '|' || buf == ';' || buf == '>' || buf == '<')
		return (0);
	return (1);
}

int				lx_is_op(char buf)
{
	if (buf == '&' || buf == '|' || buf == ';')
		return (1);
	return (0);
}

int				lx_wlen(char *buf)
{
	int			i;

	i = 0;
	while (buf[i])
	{
		if (!lx_is_word(buf[i]))
			return (i);
		i++;
	}
	return (i);
}

char			*lx_strdup(char *buf)
{
	char		*str;
	int			i;

	str = ft_strnew(lx_wlen(buf));
	i = -1;
	while (buf[++i])
	{
		if (!lx_is_word(buf[i]))
			break ;
		str[i] = buf[i];
	}
	str[i] = '\0';
	return (str);
}
