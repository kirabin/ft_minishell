# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msamual <msamual@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 14:39:50 by dmilan            #+#    #+#              #
#    Updated: 2021/04/19 11:36:05 by msamual          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
LIB			= libft/libft.a
SHELL_LIB	= libftshell.a
FLAGS		= -Wall -Wextra -Werror -g

SRC_BIN=	ft_pwd \
			ft_cd \
			ft_echo \
			ft_env \
			ft_exit \
			ft_export \
			ft_unset

SRC_ENV=	ft_env_list_new \
			ft_env_list_add_back \
			ft_env_list_clear \
			ft_env_list_get_value \
			ft_env_item_new \
			ft_env_list_remove \
			ft_env_list_replace \
			ft_env_key_exists \
			ft_env_list_print \
			ft_env_list_len \
			ft_envp_to_env_list \
			ft_env_to_charpp \
			ft_get_env_item_with_key \
			ft_env_item_free

SRC_SRC=	exec exec_support command exec_pipes exec_redirections errors_put \
			signal parse history errors write_hist parse_command read_input redirect \
			utils utils1 utils2

SRC_DEF=	names pid_functions

SRC=		$(patsubst %, built_in/%.c, $(SRC_BIN)) \
			$(patsubst %, ft_env_list/%.c, $(SRC_ENV)) \
			$(patsubst %, source/%.c, $(SRC_SRC)) \
			$(patsubst %, definitions/%.c, $(SRC_DEF)) \
			minishell.c

OBJ			= $(SRC:.c=.o)
HEADER		= includes/minishell.h
INC			= includes/

all:  $(lib) $(NAME)

$(LIB):
	make all -C libft/

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) -ltermcap

$(INC):
	make re

run:
	@./$(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -o $@ -c $< -I $(INC)

clean:
	$(MAKE) clean -C libft/
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft/
	rm -f $(NAME)
	rm -f **/a.out
	rm -f a.out
	rm -f $(SHELL_LIB)
	rm -rf minishell.dSYM

re: fclean all
