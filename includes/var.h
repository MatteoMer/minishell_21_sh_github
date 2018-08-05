/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 00:22:48 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/05 18:38:59 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "sh.h"

typedef enum			s_type
{
	LOCALE,
	EXPORT,
	ENV
}						t_type;

typedef	struct			s_env
{
	char				*name;
	char				*value;
	enum	s_type		type;
	struct 	s_env		*next;
}						t_env;

t_list						*set_varloc(t_list *tmp);

char					*env_get(char *path);
char					**env_conv_tab(void);
t_env					*env_init(char **environ);
t_env					*env_parse_tab(char **environ);
t_env					*env_new_node(void);
t_env					*g_env;

#endif
