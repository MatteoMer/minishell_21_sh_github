/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_line_edit3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 21:39:16 by mdelory           #+#    #+#             */
/*   Updated: 2018/08/08 19:07:43 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

char			*le_cursortext(t_line_edit *le, int idle)
{
	char		*str;

	if (!idle || le->len != le->cur)
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
