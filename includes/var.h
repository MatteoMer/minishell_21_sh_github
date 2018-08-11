/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 00:22:48 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/11 07:37:14 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_H
# define VAR_H
# include "sh.h"

typedef enum			e_type
{
	LOCALE,
	EXPORT,
	ENV
}						t_type;

typedef	struct			s_env
{
	char				*name;
	char				*value;
	enum e_type			type;
	struct s_env		*next;
}						t_env;

t_list					*set_varloc(t_list *tmp);
void					add_varloc(char *cmd, t_type type);
char					*env_get(char *path);
int						blt_export_error(char *cmd, int i);
int						blt_print_flag(char **cmd);
char					**env_conv_tab(void);
int						blt_change_type(char *name, t_type type);
t_env					*env_init(char **environ);
t_env					*env_parse_tab(char **environ);
t_env					*env_new_node(void);
t_env					*g_env;

#endif
