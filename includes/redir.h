/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:03:55 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/09 18:18:24 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H
# define FLAG_OPEN S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR
# include "sh.h"

int					exec_redir(t_list *lst, int io);
int					do_redir(t_list *lst);
int					wrapper_redir(t_list *lst, int out, char *name);
int					exec_agreg(t_list *lst, int out, int op);

#endif
