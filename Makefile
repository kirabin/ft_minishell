# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 14:39:50 by dmilan            #+#    #+#              #
#    Updated: 2021/02/07 10:55:26 by dmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIB			= libft/libft.a
FLAGS		= -Wall -Wextra -Werror -g
SRC			= built_in/ft_pwd.c
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