/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:45:15 by mdelory           #+#    #+#             */
/*   Updated: 2018/06/29 14:22:53 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_TERM_H
# define SH_TERM_H

# include "sh.h"

# include <stdlib.h>
# include <unistd.h>
# include <term.h>
# include <termios.h>
# include <limits.h>
# include <sys/ioctl.h>

typedef struct s_term		t_term;
typedef struct s_history	t_history;
typedef struct s_line_edit	t_line_edit;

typedef struct winsize		t_winsize;

struct						s_line_edit
{
	char					*prompt;
	char					text[LINE_MAX];
	size_t					cur;
	size_t					len;
};

struct						s_history
{
	char					*text;
	struct s_history		**head;
	struct s_history		*older;
	struct s_history		*newer;
};

struct						s_term
{
	char					buffer[LINE_MAX];
	struct s_line_edit		line_edit;
	struct s_history		*history;
	int						idle;
	int						ctn;
	t_winsize				wsize;
	struct termios			term_ios;
	struct termios			old_ios;
};

char						*term_main_loop(t_term *term);
int							term_read_input(t_term *term, char kc, int rd);
void						term_write_prompt(t_term *term);
void						term_refresh(t_term *term);
int							term_init(t_term *term);
int							term_evt_dispatch(t_term *term, char kc);
int							(*g_term_evt_esc_dispatch(void))(t_term *);
int							term_evt_del(t_term *term);
int							term_evt_bspace(t_term *term);
int							term_evt_lf(t_term *term);
int							term_evt_uparrow(t_term *term);
int							term_evt_downarrow(t_term *term);
int							term_evt_leftarrow(t_term *term);
int							term_evt_alt_leftarrow(t_term *term);
int							term_evt_rightarrow(t_term *term);
int							term_evt_alt_rightarrow(t_term *term);
int							term_evt_ht(t_term *term);
int							term_evt_cancel(t_term *term);
int							term_evt_interrupt(t_term *term);
int							term_evt_cancel(t_term *term);
int							term_evt_end(t_term *term);
int							term_evt_home(t_term *term);
int							term_evt_clear(t_term *term);
int							term_hst_add_entry(t_history **history, char *text);
int							term_hst_older(t_history **history, char *mask);
int							term_hst_newer(t_history **history, char *mask);
int							term_hst_goto_head(t_history **history);
int							term_le_set_text(t_line_edit *le, char *str);
int							term_le_clear(t_line_edit *le);
int							term_le_insert(t_line_edit *le, char c);
int							term_le_bspace(t_line_edit *le);
int							term_le_delete(t_line_edit *le);
int							term_le_move_fwd(t_line_edit *le);
int							term_le_move_bwd(t_line_edit *le);
int							term_le_move_next_word(t_line_edit *le);
int							term_le_move_prev_word(t_line_edit *le);
int							term_le_check_quote(t_line_edit *le);
void						term_exec_tc(char *str);
void						term_exec_goto(char *str, int x, int y);
void						term_set_bcolor(unsigned char r, unsigned char g,\
unsigned char b);
void						term_set_fcolor(unsigned char r, unsigned char g,\
unsigned char b);
void						term_reset_color(void);
#endif
