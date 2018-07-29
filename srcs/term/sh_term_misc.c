/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_misc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:39:00 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/17 19:50:31 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_term.h"

void			term_get_prompt(t_term *term)
{
	char		buf[PATH_MAX + 1];
	char		*prompt;

	if (term->line_edit.prompt != NULL)
		free(term->line_edit.prompt);
	getcwd(buf, PATH_MAX);
	prompt = ft_strjoin("PWD : ", ft_strrchr(buf, '/') + 1);
	term->line_edit.prompt = ft_strjoinf(prompt, " - $> ");
}
