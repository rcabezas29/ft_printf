# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 15:53:33 by rcabezas          #+#    #+#              #
#    Updated: 2020/02/08 13:48:50 by rcabezas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = ft_bzero.c \
    ft_strlen.c \
	ft_atoi.c \
    ft_isdigit.c \
    ft_isupper.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c 


RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I
INCLUDES = ./

OBJ = $(SRC:.c=.o)

$(NAME):$(SRCS) libft.h
	@gcc $(CFLAGS) $(INCLUDES) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(BOBJ)

fclean:     clean
	@$(RM) $(NAME)

re:		fclean all