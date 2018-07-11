/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:55:31 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/09 17:02:48 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "sh.h"
# include <limits.h>

t_list			*lx_main(char *buf);
int				lx_is_word(char buf);
int				lx_is_op(char buf);
int				lx_check_io(char *buf, t_list **tokens);
int				lx_wlen(char *buf);
int				lx_new_word(char *buf, t_list **tokens);
int				lx_new_op(char *buf, t_list **tokens);
int				lx_new_io(char *buf, t_list **tokens);
int				lx_quote(char *buf, t_list **tokens);
char			*lx_strdup(char *buf);
int				lx_new_redir(char *buf, t_list **tokens);
int				lx_agreg(char *buf, t_list **tokens);

#endif
