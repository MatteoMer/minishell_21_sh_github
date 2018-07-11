/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:53:40 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/23 13:54:30 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int		ps_parse_semicolon(t_list *tokens)
{
	t_list		*tmp;
	t_list		*prev;

	tmp = tokens->next;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (tmp->content_size == ';' && tokens->content_size == ';')
			return (ps_error(';'));
		prev = tokens;
		tmp = tmp->next;
		tokens = tokens->next;
	}
	if (tokens->content_size == ';')
		return (ps_error(';'));
	return (0);
}

int				ps_parse_pipe(t_list *tokens)
{
	t_list		*prev;
	t_list		*tmp;

	tmp = tokens->next;
	prev = NULL;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (!prev && tokens->content_size == '|')
			return (ps_error('|'));
		if (prev && prev->content_size != 3 && tokens->content_size == '|')
			return (ps_error('|'));
		if (tmp->content_size != 3 && tokens->content_size == '|')
			return (ps_error('|'));
		prev = tokens;
		tokens = tokens->next;
		tmp = tmp->next;
	}
	if (tokens->content_size == '|')
		return (ps_error('|'));
	return (0);
}

int				ps_parse_d(t_list *tokens, size_t c)
{
	t_list		*prev;
	t_list		*tmp;

	tmp = NULL;
	tmp = tokens->next;
	prev = NULL;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (!prev && tokens->content_size == c)
			return (ps_error(c));
		if (prev && prev->content_size != 3 && tokens->content_size == c)
			return (ps_error(c));
		if (tmp->content_size != 3 && tokens->content_size == c)
			return (ps_error(c));
		prev = tokens;
		tokens = tokens->next;
		tmp = tmp->next;
	}
	if (tokens->content_size == c)
		return (ps_error(c));
	return (0);
}

int				ps_do_parse(t_list *tokens)
{
	if (ps_parse_semicolon(tokens) == -1)
		return (-1);
	if (ps_parse_d(tokens, 125) == -1)
		return (-1);
	if (ps_parse_redir(tokens) == -1)
		return (-1);
	if (ps_parse_d(tokens, 39) == -1)
		return (-1);
	if (ps_parse_pipe(tokens) == -1)
		return (-1);
	if (ps_expansion(&tokens) == -1)
		return (-1);
	if (ps_quotes(&tokens) == -1)
		return (-1);
	return (0);
}
