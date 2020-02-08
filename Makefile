# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/15 16:40:51 by rcabezas          #+#    #+#              #
#    Updated: 2020/01/15 16:40:58 by rcabezas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILESPRINTF = ft_printf.c \
		   parse.c \
		   parsesizes.c \
		   init.c \
		   compute.c \
		   printsign.c \
		   printnegsign.c \
		   printstr.c \
		   printptr.c \
		   printuns.c \
		   printpercent.c \
		   nbrutils.c \
		   utils.c \
		   sizes_ast.c \
		   printchar.c

FILESLIBFT = ft_atoi.c \
	  ft_bzero.c \
	  ft_isdigit.c \
	  ft_isupper.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_strlen.c \

RM = rm -f

CFLAGS = -Werror -Wall -Wextra

OBJ = $(FILESPRINTF:.c=.o) $(FILESLIBFT:.c=.o)

$(NAME): $(OBJ) ft_printf.h libft.h
	@gcc $(CFLAGS) $(FILESLIBFT) $(FILESPRINTF) main.c
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norme:
	norminette
