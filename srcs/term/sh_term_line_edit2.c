/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_line_edit2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 22:16:43 by mdelory           #+#    #+#             */
/*   Updated: 2018/05/12 18:38:40 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

int					term_le_move_fwd(t_line_edit *le)
{
	if (le->cur == le->len)
		return (-1);
	le->cur++;
	return (0);
}

int					term_le_move_bwd(t_line_edit *le)
{
	if (le->cur == 0)
		return (-1);
	le->cur--;
	return (0);
}

int					term_le_move_next_word(t_line_edit *le)
{
	char			*text;

	text = le->text;
	if (le->cur == le->len)
		return (-1);
	while (text[le->cur] !=  ' ' &&\
			le->cur < le->len)
		le->cur++;
	while (text[le->cur] == ' ' &&\
			le->cur < le->len)
		le->cur++;
	return (0);
}

int					term_le_move_prev_word(t_line_edit *le)
{
	char			*text;

	text = le->text;
	if (le->cur == 0)
		return (-1);
	le->cur--;
	while (text[le->cur] ==  ' ' && le->cur > 0)
		le->cur--;
	while (le->cur > 0 && text[le->cur - 1] != ' ' &&\
			text[le->cur - 1] != '\t')
		le->cur--;
	return (0);
}

int					term_le_check_quote(t_line_edit *le)
{
	size_t			i;
	size_t			j;

	i = 0;
	while (i < le->len)
	{
		if (le->text[i] == '\'' || le->text[i] == '\"')
		{
			j = i + 1;
			while (le->text[j] != le->text[i])
			{
				if (j  == le->len)
					return ((le->text[i] == '\'' ? 1 : 2));
				j++;
			}
			i = j;
		}
		i++;
	}
	return (0);
}
