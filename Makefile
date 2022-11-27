SPATH = src/

HPATH = includes

SRCS =  ft_litoa.c ft_print_char.c ft_print_dec.c ft_print_hex.c ft_print_pointer.c ft_print_string.c \
		ft_printf.c ft_strlen.c ft_strdup.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

AR = ar -rcs

$(NAME):	$(addprefix $(SPATH),$(OBJS))
			$(AR) $(NAME) $(addprefix $(SPATH),$(OBJS))

$(SPATH)%.o:	$(addprefix $(SPATH),%.c)
				$(CC) $(CFLAGS) -c $< -I$(HPATH) -o $@

all: $(NAME)

clean:
		$(RM) $(addprefix $(SPATH),$(OBJS)) 

fclean:	clean
		$(RM) $(NAME) 

re:	fclean all

.PHONY: all clean fclean re 