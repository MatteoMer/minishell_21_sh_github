/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:29:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/11 07:33:19 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				sig_handler_int(int signo)
{
	if (signo == SIGINT)
		if (g_loc.g_pid != 0)
		{
			kill(g_loc.g_pid, SIGINT);
		}
}

void				sig_handler(void)
{
	signal(SIGINT, sig_handler_int);
}
