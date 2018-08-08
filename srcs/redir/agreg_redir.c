/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agreg_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:26:11 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/08 17:22:31 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int			exec_agreg_close(int out)
{
	if (close(out) == -1)
	{
		ft_putendl_fd("21sh: bad file descriptor", 2);
		return (-1);
	}
	return (0);
}

static int			exec_agreg_output(t_list *lst, int out)
{
	int		s_op;

	s_op = -1;
	lst = lst->next->next;
	if (!lst)
		s_op = 1;
	else if (lst->content_size == 10)
		return (exec_agreg_close(out));
	else if (lst->content_size == 4)
		s_op = ((char *)lst->content)[0];
	if (s_op == -1)
		s_op = 1;
	dup2(s_op, out);
	close(s_op);
	return (0);
}

static int			exec_agreg_input(t_list *lst, int out)
{
	int		s_op;

	s_op = -1;
	lst = lst->next->next;
	if (!lst)
		s_op = 1;
	else if (lst->content_size == 10)
		return (exec_agreg_close(out));
	else if (lst->content_size == 4)
		s_op = ((char *)lst->content)[0];
	if (s_op == -1)
		s_op = 1;
	dup2(out, s_op);
	close(out);
	return (0);
}

int					exec_agreg(t_list *lst, int out, int op)
{
	if (op == 6)
		return (exec_agreg_output(lst, out));
	else if (op == 5)
		return (exec_agreg_input(lst, out));
	return (0);
}
