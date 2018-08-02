/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 00:22:48 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/02 20:02:27 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR
# define VAR_H
# include "sh.h"

typedef	struct			s_env
{
	char				*name;
	char				*value;
	struct s_env		*next;
}						t_env;

//t_var					*var_new(char *name, char *value);
//void					var_add(t_var **var_lst, t_var *var);
//char					*var_get_value(char *name);

char					*env_get(char *path);
char					**env_conv_tab(void);
t_env					*env_init(char **environ);
t_env					*env_parse_tab(char **environ);
t_env					*env_new_node(void);
t_env					*g_env;

#endif
