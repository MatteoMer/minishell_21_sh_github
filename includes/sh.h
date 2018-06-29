/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:31:04 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/25 11:57:35 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <fcntl.h>
# include <sys/param.h>
# include <signal.h>
# include "../libft/incs/libft.h"
# include "parse.h"
# include "lexer.h"
# include "env.h"
# include "sh_term.h"

pid_t		g_pid;

#endif
