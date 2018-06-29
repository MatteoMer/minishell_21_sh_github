/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:29:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/29 14:01:25 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				sig_handler_int(int signo)
{
	if (signo == SIGINT)
		if (g_pid != 0)
		{
			kill(g_pid, SIGINT);
		}
}

void				sig_handler(void)
{
	signal(SIGINT, sig_handler_int);
}
