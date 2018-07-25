/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:00:08 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/25 21:27:33 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int			lx_if(char *buf, t_list **tokens)
{
	int		len;

	len = 0;
	if (*buf == '>' || *buf == '<')
		len += lx_new_redir(buf, tokens) - 1;
	else if (ft_isdigit(*buf))
		len += lx_check_io(buf, tokens) - 1;
	else if (lx_is_word(*buf))
		len += lx_new_word(buf, tokens) - 1;
	else if (lx_is_op(*buf))
		len += lx_new_op(buf, tokens) - 1;
	return (len);
}

t_list				*lx_main(char *buf)
{
	t_list		*tokens;
	int			i;

	tokens = NULL;
	while (buf && *buf)
	{
		while (*buf == ' ' || *buf == '\t')
			buf++;
		if (*buf == '"' || *buf == 39)
		{
			if ((i = lx_quote(buf, &tokens)) == -1)
				return (NULL);
			else
				buf += i;
		}
		else if (*buf == '#')
			return (tokens);
		buf += lx_if(buf, &tokens);
		if (*buf == '\0')
			return (tokens);
		buf++;
		while (*buf == ' ' || *buf == '\t')
			buf++;
	}
	return (tokens);
}
