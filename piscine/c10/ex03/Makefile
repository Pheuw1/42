NAME = ft_hexdump

SRCS = display_file.c display_file2.c ft_strings.c hexascii.c main.c

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