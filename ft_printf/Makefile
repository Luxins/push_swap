NAME = libftprintf.a

SRCS = ft_printf.c ft_printchar.c ft_printstr.c ft_printhex.c ft_printnumb.c

COMPILER = cc

CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:%.c=%.o}

all: $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(NAME): all

$(OBJS): %.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean:
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re