NAME = do-op

SRCS =	ft_atoi.c do_op.c ft_putnbr.c ft_putstr.c ops.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)
	
$(NAME) : $(OBJS)
	gcc -Wall -Wextra -Werror $^ -o  $@

.PHONY: clean fclean re all

libft.a : $(OBJS)
	ar -src $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)