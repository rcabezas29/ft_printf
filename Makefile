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
		   printascii.c \
		   printptr.c \
		   printuns.c \
		   printpercent.c \
		   printbinary.c \
		   nbrutils.c \
		   utils.c

FILESLIBFT = ft_atoi.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_isupper.c \
	  ft_lstadd_back_bonus.c \
	  ft_lstadd_front_bonus.c \
	  ft_lstclear_bonus.c \
	  ft_lstdelone_bonus.c \
	  ft_lstiter_bonus.c \
	  ft_lstmap_bonus.c \
	  ft_lstnew_bonus.c \
	  ft_lstlast_bonus.c \
	  ft_lstsize_bonus.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_split.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_tolower.c \
	  ft_toupper.c 

RM = rm -f

CFLAGS = -Werror -Wall -Wextra

OBJ = $(FILESPRINTF:.c=.o) $(FILESLIBFT:.c=.o)

$(NAME): $(OBJ) ft_printf.h libft.h
	@gcc $(CFLAGS) $(FILESLIBFT) $(FILESPRINTF) testmain.c
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
