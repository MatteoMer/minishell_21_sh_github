/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:19:15 by mmervoye          #+#    #+#             */
/*   Updated: 2018/07/09 11:26:15 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "sh.h"

typedef struct s_env	t_env;
typedef struct			s_ps_tree
{
	struct s_ps_tree	*left;
	struct s_ps_tree	*right;
	size_t				op_number;
	t_list				*content;
}						t_ps_tree;
int						ps_quotes(t_list **tokens);
t_list					*ps_check_content(t_list *tokens);
t_ps_tree				*ps_main(char *buf);
t_ps_tree				*ps_init_tree(void);
t_ps_tree				*ps_recursive(t_list **tokens);
int						ps_parse_redir_check(t_list *tokens, int i);
int						bn_wrap_exec(char **bn_tab, char **cpath,\
char **cmd_bn_tab, t_ps_tree *tree);
int						bn_func_exec(char **bn_tab, char **cpath,\
char **cmd_bn_tab, t_ps_tree *tree);
int						ps_parse_redir(t_list *tokens);
int						ps_do_parse(t_list *tokens);
int						ps_error(char c);
int						ps_expansion(t_list **tokens);
int						ps_do_recursive_redir(t_ps_tree **ast, t_list **tokens);
int						ps_launch_recursive(t_ps_tree **ast, t_list **tokens,\
t_list **ptr, t_list **prev);
void					ps_ast_visu(t_ps_tree *ast);
void					ps_free_ast(t_ps_tree **ast);
int						redir_agreg_check(t_list **tokens, char *buf);
int						bn_rec(t_ps_tree *tree, char op);
int						free_and_return(char ***ft_tab);
char					**ft_sortpath(char **bn_tab, char **cmd_bn_tab);
int						bn_rec(t_ps_tree *tree, char op);
int						bn_binary(t_ps_tree *tree);
char					*bn_rec_redir_right(t_ps_tree *tree, char prev, char c);
t_ps_tree				*bn_rec_redir_left(t_ps_tree *tree, char first);
int						bn_redir_main(t_ps_tree *tree);
char					*bn_read_all_file(char *name);
int						bn_execve1(char *path, char **bn_tab, t_list *lst);
int						g_status;
int						blt_error(char **cmd, int i);
int						blt_env_error(char **cmd, int i);
int						blt_bn_error(char **cmd1, char **cmd, int i, int ret);
int						blt_check(char	**cmb_bn_tab);
int						blt_env(char **cmd);
t_env					*blt_list_clone(t_env *env);
char					**blt_conv_tab(t_env *env);
char					**blt_getpath(t_env *env);
int						blt_env_check(char **cmd);
int						blt_setenv(char **cmd, t_env **env, int i);
int						blt_unsetenv(char **cmd);
void					blt_add_maillon(t_env **alst, t_env *new);
t_env					*blt_new_list(void);
int						blt_cd(char **cmd);
int						blt_cd_error(int i, char *str);
int						blt_cd_launch(char *path, int nb);
int						blt_cd_launch_sp(int flags, int n);
int						blt_cd_flag(char **cmd, int *index);
char					*blt_cd_normalize(char *s);
int						blt_cd_error(int i, char *str);
void					blt_free_env(t_env **ptr);
int						blt_execve(char *path, char **cmd, t_env *env);
char					*blt_env_access(char **cmd, char *str,\
char **path, t_env *env);
int						do_pipe(t_ps_tree *tree);
void					multi_pipe(t_ps_tree *tree);
int						exec_wrapper(t_ps_tree *tree);
void					sig_handler_int(int signo);
void					sig_handler();
int						redir_exec(char **bn_tab, char **cpath,\
char **cmd_bn_tab, t_ps_tree *tree);

#endif
