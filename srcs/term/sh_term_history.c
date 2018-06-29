/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:55:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/29 14:25:27 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

int				term_hst_add_entry(t_history **history, char *text)
{
	t_history	*h;

	if (!(h = (t_history *)ft_memalloc(sizeof(t_history))))
		return (-1);
	if (*history)
	{
		term_hst_goto_head(history);
		(*history)->newer = h;
		h->head = (*history)->head;
	}
	else
	{
		h->head = (t_history **)ft_memalloc(sizeof(t_history *));
		h->newer = NULL;
	}
	*(h->head) = h;
	h->text = text;
	h->older = *history;
	*history = h;
	return (0);
}

int				term_hst_older(t_history **history, char *mask)
{
	t_history	*hst;

	if (!(*history)->older)
		return (-1);
	hst = (*history)->older;
	while (hst)
	{
		if (ft_strncmp(hst->text, mask, ft_strlen(mask)) == 0)
		{
			*history = hst;
			return (0);
		}
		hst = hst->older;
	}
	return (-1);
}

int				term_hst_newer(t_history **history, char *mask)
{
	t_history	*hst;

	if (!(*history)->newer)
		return (-1);
	hst = (*history)->newer;
	while (hst)
	{
		if (ft_strncmp(hst->text, mask, ft_strlen(mask)) == 0)
		{
			*history = hst;
			return (0);
		}
		hst = hst->newer;
	}
	return (-1);
}

int				term_hst_goto_head(t_history **history)
{
	*history = *((*history)->head);
	return (0);
}
