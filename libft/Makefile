# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 11:34:55 by dmilan            #+#    #+#              #
#    Updated: 2020/12/09 09:58:09 by dmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
#                                                                              #
#                                VARIABLES                                     #
#                                                                              #
################################################################################

NAME      = libft.a
HEADER    = libft.h
CCFLAGS   = -Wall -Wextra -Werror

SRC_PRINT = ft_printf.c \
			print_c.c \
			print_s.c \
			print_p.c \
			print_di.c \
			print_u.c \
			print_x.c \
			print_percent.c \
			ft_printf_support.c

SRC_STR   = ft_strchr.c \
			ft_strcount.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strjoinfree.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_strskip.c \
			ft_strskip_char.c \
			ft_strfill.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_substr.c

SRC_LST   = ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstfind.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstmerge.c \
			ft_lstnew.c \
			ft_lstrev.c \
			ft_lstsize.c

SRC_CHR   = ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isblank.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_tolower.c \
			ft_toupper.c

SRC_INT   = ft_leni.c \
			ft_min.c \
			ft_abs.c \
			ft_swapi.c \
			ft_max.c 
			
SRC_PUT   = ft_putc_fd.c \
			ft_putuc_fd.c \
			ft_puti_fd.c \
			ft_putstr_fd.c \
			ft_putstrn_fd.c \
			ft_putui_fd.c \
			ft_putui_hex_fd.c \
			ft_putcppn_fd.c \
			ft_putul_hex_fd.c

SRC_MEM   = ft_bzero.c \
			ft_calloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c

SRC_POINT = ft_point_add.c \
			ft_point_new.c \
			ft_point_len.c \
			ft_point_rotate.c

SRC       = $(wildcard ft_str/ft_*.c)   \
			$(wildcard ft_lst/ft_*.c)   \
			$(wildcard ft_mem/ft_*.c)   \
			$(wildcard ft_chr/ft_*.c)   \
			$(wildcard ft_printf/*.c)   \
			$(wildcard ft_put/ft_*.c)   \
			$(wildcard ft_int/ft_*.c)   \
			$(wildcard ft_point/ft_*.c) \
			$(wildcard ft_color/ft_*.c) \
			ft_uitoa.c \
			ft_lenui.c \
			ft_lenui_hex.c \
			ft_lenul_hex.c \
			ft_split.c \
			get_next_line.c

OBJ       = $(SRC:.c=.o)

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
