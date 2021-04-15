# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 11:34:55 by dmilan            #+#    #+#              #
#    Updated: 2021/04/15 14:30:29 by dmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
#                                                                              #
#                                VARIABLES                                     #
#                                                                              #
################################################################################

NAME=		libft.a
HEADER=		libft.h
CCFLAGS=	-Wall -Wextra -Werror

SRC_STR=	ft_atoi \
			ft_itoa \
			ft_strchr \
			ft_strcount \
			ft_strdup \
			ft_strfill \
			ft_string_is_path \
			ft_strjoin \
			ft_strjoin_free \
			ft_strjoin \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strmapi \
			ft_strncmp \
			ft_strnew \
			ft_strnstr \
			ft_strrchr \
			ft_strskip \
			ft_strskip_char \
			ft_strtrim \
			ft_substr \
			is_long_long

SRC_LST=	ft_lst_bubble_sort \
			ft_lst_put \
			ft_lst_swap \
			ft_lstadd_back \
			ft_lstadd_front \
			ft_lstclear \
			ft_lstdelone \
			ft_lstfind \
			ft_lstiter \
			ft_lstlast \
			ft_lstmap \
			ft_lstmerge \
			ft_lstnew \
			ft_lstrev \
			ft_lstsize

SRC_CHR=	ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isblank \
			ft_isdigit \
			ft_isprint \
			ft_isspace \
			ft_tolower \
			ft_toupper

SRC_INT=	ft_leni \
			ft_min \
			ft_abs \
			ft_swapi \
			ft_max

SRC_PUT=	ft_putchar_fd \
			ft_putcpp_fd \
			ft_putendl \
			ft_putint \
			ft_putnbr_fd \
			ft_putstr \
			ft_putstr_fd

SRC_MEM=	ft_bzero \
			ft_calloc \
			ft_memccpy \
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memmove \
			ft_memset

SRC_FREE=	free_cpp

SRC=		$(patsubst %, ft_str/%.c, $(SRC_STR)) \
			$(patsubst %, ft_lst/%.c, $(SRC_LST)) \
			$(patsubst %, ft_mem/%.c, $(SRC_MEM)) \
			$(patsubst %, ft_chr/%.c, $(SRC_CHR)) \
			$(patsubst %, ft_put/%.c, $(SRC_PUT)) \
			$(patsubst %, ft_int/%.c, $(SRC_INT)) \
			$(patsubst %, free/%.c, $(SRC_FREE)) \
			ft_uitoa.c \
			ft_lenui.c \
			ft_lenui_hex.c \
			ft_lenul_hex.c \
			ft_split.c \
			get_next_line.c

OBJ=$(SRC:.c=.o)

################################################################################
#                                                                              #
#                                RULES                                         #
#                                                                              #
################################################################################
.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c $(HEADER)
	gcc -c $(CCFLAGS) $< -o $@ -I.

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
