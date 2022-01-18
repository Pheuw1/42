NAME = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o

%.c%.o:
	ggc -Wall -Wextra -Werror -c $< -I./includes -o $(<:.c=.o)

.PHONY: clean fclean re all

libft.a : $(OBJS)
	ar -src $(NAME) $(OBJS) 
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a

re: fclean all

all: $(NAME)
	

