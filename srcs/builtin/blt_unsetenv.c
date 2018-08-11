/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:21:03 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/11 03:06:52 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				blt_unsetenv(char **cmd)
{
	blt_setenv(cmd, &(g_env), LOCALE, 0);
	return (1);
}
