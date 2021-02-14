# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msamual <msamual@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 14:39:50 by dmilan            #+#    #+#              #
#    Updated: 2021/02/14 12:10:59 by msamual          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
LIB			= libft/libft.a
SHELL_LIB	= libftshell.a
FLAGS		= -Wall -Wextra -g    # remove -g flag
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
			  ft_env_list/ft_env_list_print.c

OBJ			= $(SRC:.c=.o)
HEADER		= minishell.h

all: $(NAME)

$(LIB):
	make all -C libft/

$(NAME): $(OBJ) $(LIB)
	ar -rcs $(SHELL_LIB) $(OBJ) libft/*.o libft/*/*.o
	make build

build:
	gcc $(FLAGS) minishell.c parse.c $(SRC) $(SHELL_LIB) -o $(NAME) -I.  # change to obj###################################

run:
	@echo "\n"
	@./$(NAME)

%.o: %.c $(HEADER)
	gcc -g -c $(FLAGS) $< -o $@ -I.

clean:
	$(MAKE) clean -C libft/
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft/
	rm -f $(NAME)
	rm -f $(SHELL_LIB)

re: fclean all
