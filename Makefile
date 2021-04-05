# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 14:39:50 by dmilan            #+#    #+#              #
#    Updated: 2021/04/03 14:16:18 by dmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
LIB			= libft/libft.a
SHELL_LIB	= libftshell.a
FLAGS		= -Wall -Wextra -Werror -g
SRC			= built_in/ft_pwd.c \
			  built_in/ft_cd.c \
			  built_in/ft_echo.c \
			  built_in/ft_env.c \
			  built_in/ft_exit.c \
			  built_in/ft_export.c \
			  built_in/ft_unset.c \
			  ft_env_list/ft_env_list_new.c \
			  ft_env_list/ft_env_list_add_back.c \
			  ft_env_list/ft_env_list_clear.c \
			  ft_env_list/ft_env_list_get_value.c \
			  ft_env_list/ft_env_item_new.c \
			  ft_env_list/ft_env_list_remove.c \
			  ft_env_list/ft_env_list_replace.c \
			  ft_env_list/ft_env_key_exists.c \
			  ft_env_list/ft_env_list_print.c \
			  ft_env_list/ft_env_list_len.c \
			  ft_env_list/convert_envp_to_list.c \
			  ft_env_list/ft_env_to_charpp.c \
			  minishell.c \
			  parse.c \
			  parse_command.c \
			  read_input.c \
			  history.c \
			  write_hist.c \
			  execute.c \
			  errors.c \
			  exec.c

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