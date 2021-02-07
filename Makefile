# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 14:39:50 by dmilan            #+#    #+#              #
#    Updated: 2021/02/07 13:03:58 by dmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIB			= libft/libft.a
FLAGS		= -Wall -Wextra -Werror -g
SRC			= built_in/ft_pwd.c \
			  built_in/ft_cd.c \
			  built_in/ft_echo.c \
			  built_in/ft_env.c \
			  built_in/ft_exit.c \
			  built_in/ft_export.c \
			  built_in/ft_unset.c

OBJ			= $(SRC:.c=.o)
HEADER		= minishell.h

all: $(NAME)

$(LIB):
	make all -C libft/

$(NAME): $(OBJ) $(LIB)
	ar -rcs $(NAME) $(OBJ) libft/*.o libft/*/*.o

build:
	gcc $(FLAGS) minishell.c $(SRC) $(NAME) -I.  # change to obj###################################
	./a.out

%.o: %.c $(HEADER)
	gcc -g -c $(FLAGS) $< -o $@ -I.

clean:
	$(MAKE) clean -C libft/
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft/
	rm -f $(NAME)

re: fclean all

run: 
	./$(NAME)