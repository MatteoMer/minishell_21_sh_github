/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:31:04 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/02 19:46:04 by xmazella         ###   ########.fr       */
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
# include "var.h"
# include "sh_term.h"
# include "redir.h"

typedef struct	s_global
{
	pid_t		g_pid;
}				t_global;

t_global		g;


#endif
