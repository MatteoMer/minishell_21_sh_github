/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_line_edit3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 21:39:16 by mdelory           #+#    #+#             */
/*   Updated: 2018/08/15 03:01:10 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

static char				term_le_get_closing_char(char c)
{
	if (c == 34 || c == 39)
		return (c);
	if (c == '(')
		return (')');
	if (c == '{')
		return ('}');
	return (-1);
}

int						term_le_check_quote(t_line_edit *le)
{
	size_t			i;
	char			c;
	int				single;

	i = 0;
	single = 0;
	while (le->text[i])
	{
		if (le->text[i] != '\\')
		{
			if (single)
			{
				if (le->text[i] == c)
					single = 0;
			}
			else if ((c = term_le_get_closing_char(le->text[i])) > 0)
				single = 1;
		}
		else
			i++;
		i++;
	}
	return (single);
}

char					*le_cursortext(t_line_edit *le, int cursor)
{
	char		*str;

	if (cursor)
	{
		str = ft_strnew(le->len + 13);
		ft_strncat(str, le->text, le->cur);
		ft_strcat(str, "\033[47;97m");
		if (le->len != le->cur)
		{
			if (le->text[le->cur] == '\n')
				ft_strcat(str, " \033[0m\n");
			else
			{
				ft_strncat(str, &le->text[le->cur], 1);
				ft_strcat(str, "\033[0m");
			}
			ft_strcat(str, le->text + le->cur + 1);
		}
		else
			ft_strcat(str, " \033[0m");
	}
	else
		str = ft_strdup(le->text);
	return (str);
}
