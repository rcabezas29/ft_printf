# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/19 10:10:53 by rcabezas          #+#    #+#              #
#    Updated: 2019/12/19 10:12:22 by rcabezas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 

SRC = 

RM = rm -f

CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./

OBJ = $(SRC:.c=.o)

$(NAME):$(SRCS) libft.h
	@gcc $(CFLAGS) $(INCLUDES) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean:     clean
	@$(RM) $(NAME)

re:		fclean all
