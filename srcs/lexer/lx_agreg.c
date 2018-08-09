/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_agreg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:26:48 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 18:12:27 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int			do_agreg_close(t_list **tokens)
{
	t_list			*new;

	if ((new = ft_lstnew(NULL, 0)) == NULL)
		malloc_error();
	if ((new->content = ft_strnew(1)) == NULL)
		malloc_error();
	((char *)new->content)[0] = '-';
	((char *)new->content)[1] = '\0';
	new->content_size = 10;
	ft_lstadd(tokens, new);
	return (1);
}

static int			do_agreg_io(char *buf, t_list **tokens)
{
	t_list			*new;

	if ((new = ft_lstnew(NULL, 0)) == NULL)
		malloc_error();
	if ((new->content = ft_strnew(1)) == NULL)
		malloc_error();
	((char *)new->content)[0] = *buf;
	((char *)new->content)[1] = '\0';
	new->content_size = 4;
	ft_lstadd(tokens, new);
	return (1);
}

static int			wrapper_agreg(char *buf, t_list **tokens)
{
	if (*buf == '-')
		return (do_agreg_close(tokens));
	else
		return (do_agreg_io(buf, tokens));
}

int					lx_agreg(char *buf, t_list **tokens)
{
	t_list		*agreg;

	if ((agreg = ft_lstnew(NULL, 0)) == NULL)
		malloc_error();
	agreg->content_size = 9;
	ft_lstadd(tokens, agreg);
	buf += 2;
	if ((ft_isdigit(*buf) == 0 && *buf != '-'))
		return (2);
	return (2 + wrapper_agreg(buf, tokens));
}
