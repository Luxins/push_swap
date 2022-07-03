OBJS = medium.o checkers.o validation.o init_link.o utils_main.o \
		push_swap.o sort.o freeing.o small_sort.o
DIRS = libft/libft.a ft_printf/libftprintf.a
NAME = push_swap
#CFLAGS = -Werror -Wextra -Wall

all: $(OBJS)
	$(MAKE) -C ft_printf
	$(MAKE) -C libft
	gcc -g $(OBJS) -o $(NAME) $(DIRS)

labs: $(OBJS)
	$(MAKE) -C libft
	gcc -g $(OBJS) -o $(NAME) $(DIRS)

clean:
	rm -f $(wildcard *.o)

fclean:
	rm -f push_swap

re: clean fclean all