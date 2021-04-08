# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 14:39:50 by dmilan            #+#    #+#              #
#    Updated: 2021/04/08 12:57:20 by dmilan           ###   ########.fr        #
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

SRC=		$(patsubst %, built_in/%.c, $(SRC_BIN)) \
			$(patsubst %, ft_env_list/%.c, $(SRC_ENV)) \
			minishell.c \
			parse.c \
			parse_command.c \
			read_input.c \
			history.c \
			write_hist.c \
			execute.c \
			errors.c \
			exec.c \
			definitions/names.c

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
	@echo "\n"
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