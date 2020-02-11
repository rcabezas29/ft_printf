# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 17:41:26 by rcabezas          #+#    #+#              #
#    Updated: 2020/02/11 17:45:01 by rcabezas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRC_PF =  compute.c ft_printf.c utils.c init.c nbrutils.c parse.c parsesizes.c \
		printchar.c printnegsign.c printpercent.c printptr.c printsign.c \
		printstr.c printuns.c sizes_ast.c
		
SRC_LFT = ft_atoi.c ft_bzero.c ft_isdigit.c ft_isupper.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_strlen.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJ_SRC = $(SRC_PF:.c=.o)

OBJ_LFT = $(SRC_LFT:.c=.o)

LIBFT_PATH = libft

SRC_PATH = srcs

INCLUDES_PATH = includes

LFT = $(addprefix $(LIBFT_PATH)/, $(OBJ_LFT))

SRC = $(addprefix $(SRC_PATH)/, $(OBJ_SRC))

INCLUDE_PF = ft_printf.h

INCLUDE_LFT = libft.h

PF_LIB = $(addprefix $(INCLUDES_PATH)/, $(INCLUDE_PF))

LFT_LIB = $(addprefix $(LIBFT_PATH)/, $(INCLUDE_LFT))

all: $(NAME)

$(NAME): $(SRC) $(LFT) $(PF_LIB) $(LFT_LIB)
	ar rc $(NAME) $(SRC) $(LFT)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(SRC) $(LFT)

fclean: clean
	rm -f $(NAME)

re: fclean all
