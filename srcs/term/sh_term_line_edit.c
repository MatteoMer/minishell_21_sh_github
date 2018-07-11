/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_line_edit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:55:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/29 14:25:36 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

int				term_le_set_text(t_line_edit *le, char *str)
{
	int			l;

	l = ft_strlen(str);
	if (l > LINE_MAX)
		return (-1);
	ft_bzero(le->text, le->len);
	ft_strncpy(le->text, str, l);
	le->len = l;
	le->cur = l;
	return (0);
}

int				term_le_clear(t_line_edit *le)
{
	ft_bzero(le->text, le->len);
	le->len = 0;
	le->cur = 0;
	return (0);
}

int				term_le_insert(t_line_edit *le, char c)
{
	char		*b;

	if (le->len == LINE_MAX)
		return (-1);
	b = le->text + le->cur;
	ft_memmove(b + 1, b, le->len - le->cur);
	le->text[le->cur] = c;
	le->cur++;
	le->len++;
	return (0);
}

int				term_le_bspace(t_line_edit *le)
{
	char		*b;

	if (le->cur == 0)
		return (-1);
	b = (le->text + le->cur);
	ft_memmove(b - 1, b, (le->len - le->cur) + 1);
	le->cur--;
	le->len--;
	return (0);
}

int				term_le_delete(t_line_edit *le)
{
	char		*b;

	if (le->cur == le->len)
		return (-1);
	b = le->text + le->cur;
	ft_memmove(b, b + 1, le->len - le->cur);
	le->len--;
	return (0);
}
