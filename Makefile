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

LIBFT = libft

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

RM = rm -f

CFLAGS = -Werror -Wall -Wextra

OBJ = $(FILESPRINTF:.c=.o)

$(NAME): $(OBJ) ft_printf.h
	@make -C $(LIBFT)
	@cp libft/libft.a $(NAME)
	@gcc $(CFLAGS) $(FILESPRINTF) libft/*.o main.c
	@ar rc $(NAME) $(OBJ) libft/*.o
	@ranlib $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

norme:
	norminette
