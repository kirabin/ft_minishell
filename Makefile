# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 14:39:50 by dmilan            #+#    #+#              #
#    Updated: 2020/12/24 11:52:27 by dmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIB			= libft/libft.a
FLAGS		= -Wall -Wextra -Werror
SRC			= 
OBJ			= $(SRC:.c=.o)
HEADER		= 

all: $(NAME)

$(LIB):
	make all -C libft/

$(NAME): $(OBJ) $(LIB)
	ar -rcs $(NAME) $(OBJ) libft/*.o libft/*/*.o

build:
	gcc $(FLAGS) main.c $(SRC)
	./a.out

%.o: %.c $(HEADER)
	gcc -g -c $(FLAGS) $<

clean:
	$(MAKE) clean -C libft/
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft/
	rm -f $(NAME)

re: fclean all

run: 
	./$(NAME)