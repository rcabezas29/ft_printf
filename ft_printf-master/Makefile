NAME = libftprintf.a
PATHPRINTF = ./srcs/
PATHLIBFT = ./libft/
PATHOBJ = ./objs/
FILESPRINTF = ft_printf \
		   ft_parse \
		   ft_parsesizes \
		   ft_init \
		   ft_compute \
		   ft_printsgn \
		   ft_printsgn_neg \
		   ft_printascii \
		   ft_printptr \
		   ft_printuns \
		   ft_printfloat \
		   ft_printpercent \
		   ft_printbin \
		   ft_nbutils \
		   ft_utils
FILESLIBFT = ft_atoi \
	  ft_bzero \
	  ft_isalnum \
	  ft_isalpha \
	  ft_isascii \
	  ft_isdigit \
	  ft_islower \
	  ft_isprint \
	  ft_isupper \
	  ft_itoa \
	  ft_lstadd \
	  ft_lstdel \
	  ft_lstdelone \
	  ft_lstiter \
	  ft_lstmap \
	  ft_lstnew \
	  ft_lstend \
	  ft_memalloc \
	  ft_memccpy \
	  ft_memchr \
	  ft_memcmp \
	  ft_memcpy \
	  ft_memdel \
	  ft_memdup \
	  ft_memmove \
	  ft_memset \
	  ft_putchar \
	  ft_putchar_fd \
	  ft_putendl \
	  ft_putendl_fd \
	  ft_putnbr \
	  ft_putnbr_fd \
	  ft_putstr \
	  ft_putstr_fd \
	  ft_strcat \
	  ft_strchr \
	  ft_strclr \
	  ft_strcmp \
	  ft_strcpy \
	  ft_strdel \
	  ft_strdel \
	  ft_strdup \
	  ft_strequ \
	  ft_striter \
	  ft_striteri \
	  ft_strjoin \
	  ft_strlcat \
	  ft_strlen \
	  ft_strmap \
	  ft_strmapi \
	  ft_strncat \
	  ft_strcmp \
	  ft_strncmp \
	  ft_strncpy \
	  ft_strnequ \
	  ft_strnew \
	  ft_strnstr \
	  ft_strrchr \
	  ft_strsplit \
	  ft_strstr \
	  ft_strsub \
	  ft_strtrim \
	  ft_tolower \
	  ft_toupper \
	  ft_print_bits \
	  ft_printt \
	  get_next_line
SRCLIBFT = $(addprefix $(PATHLIBFT), $(addsuffix .c, $(FILESLIBFT)))
OBJLIBFT = $(addprefix $(PATHOBJ), $(addsuffix .o, $(FILESLIBFT:.c=.o)))
INCLIBFT = $(PATHLIBFT)
SRCPRINTF = $(addprefix $(PATHPRINTF), $(addsuffix .c, $(FILESPRINTF)))
OBJPRINTF = $(addprefix $(PATHOBJ), $(addsuffix .o, $(FILESPRINTF:.c=.o)))
INCPRINTF = ./includes/
CC = clang $(CFLAGS)
CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJLIBFT) $(OBJPRINTF)
	@echo "Creating $(NAME)"
	@ar rc $(NAME) $(OBJLIBFT) $(OBJPRINTF)
	@ranlib $(NAME)
	@echo "Successfully created $(NAME)"

$(PATHOBJ)%.o: $(PATHLIBFT)%.c
	@mkdir $(PATHOBJ) 2> /dev/null || true
	@$(CC) -o $@ -c $< -I$(INCLIBFT)

$(PATHOBJ)%.o: $(PATHPRINTF)%.c
	@mkdir $(PATHOBJ) 2> /dev/null || true
	@$(CC) -o $@ -c $< -I$(INCPRINTF)

clean:
	@echo "Removing objects files of $(NAME)"
	@/bin/rm -f $(OBJPRINTF) $(OBJLIBFT)
	@/bin/rmdir $(PATHOBJ) 2> /dev/null || true

fclean: clean
	@echo "Removing $(NAME)"
	@/bin/rm -f $(NAME)

re: fclean all

norme:
	norminette
