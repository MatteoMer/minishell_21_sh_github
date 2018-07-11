# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 11:21:35 by mmervoye          #+#    #+#              #
#    Updated: 2018/07/11 14:06:52 by mmervoye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC_CORE =		srcs/core/main.c

SRC_LX =		srcs/lexer/lx_io.c\
				srcs/lexer/lx_main.c\
				srcs/lexer/lx_misc.c\
				srcs/lexer/lx_operator.c\
				srcs/lexer/lx_quoting.c\
				srcs/lexer/lx_redir.c\
				srcs/lexer/lx_agreg.c\
				srcs/lexer/lx_word.c

SRC_PS =		srcs/parser_ast/ps_do_parse.c\
				srcs/parser_ast/ps_main.c\
				srcs/parser_ast/ps_misc.c\
				srcs/parser_ast/ps_parse_redir.c\
				srcs/parser_ast/ps_recursive.c\
				srcs/parser_ast/ps_expansion.c\
				srcs/parser_ast/ps_quotes.c

SRC_TERM =		srcs/term/sh_term.c\
				srcs/term/sh_term_cmd.c\
				srcs/term/sh_term_event.c\
				srcs/term/sh_term_event2.c\
				srcs/term/sh_term_event3.c\
				srcs/term/sh_term_event4.c\
				srcs/term/sh_term_history.c\
				srcs/term/sh_term_line_edit.c\
				srcs/term/sh_term_line_edit2.c

SRC_ENV =		srcs/env/env_init.c\
				srcs/env/env_get.c\
				srcs/env/env_conv.c

SRC_BINARY =	srcs/binary/bn_rec.c\
				srcs/binary/bn_rec2.c\
				srcs/binary/bn_wrapper.c\
				srcs/redir/do_redir.c\
				srcs/redir/wrapper_redir.c\
				srcs/redir/agreg_redir.c\
				srcs/pipe/do_pipe.c\
				srcs/signaux/signal.c

SRC_BUILTIN =	srcs/builtin/blt_check.c\
				srcs/builtin/blt_env.c\
				srcs/builtin/blt_env2.c\
				srcs/builtin/blt_env_check.c\
				srcs/builtin/blt_setenv.c\
				srcs/builtin/blt_unsetenv.c\
				srcs/builtin/blt_error.c\
				srcs/builtin/blt_cd.c\
				srcs/builtin/blt_cd_launch.c\
				srcs/builtin/blt_cd_flag.c\
				srcs/builtin/blt_cd_normalize.c\
				srcs/builtin/blt_free_env.c

SRC = $(SRC_TERM) $(SRC_LX) $(SRC_PS) $(SRC_CORE) $(SRC_ENV) $(SRC_BINARY) \
	  $(SRC_BUILTIN) $(SRC_REDIR)

HEADER = sh.h

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iincludes -g3

LIBFLAGS = -Llibft -lft -ltermcap

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(OBJ) $(LIBFLAGS) -o $(NAME)

clean:
	@make clean -C libft/
	@rm -Rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -Rf $(NAME)

libft: 
	@make -C libft

re: fclean all

.PHONY: all clean fclean re libft
