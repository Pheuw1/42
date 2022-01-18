SRCS		= main.c ft_tail2.c

OBJS		= ${SRCS:.c=.o}

NAME 		= ft_tail

.c.o:
	gcc -Wall -Wextra -Werror -c -I. $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc -Wall -Wextra -Werror $^ -o $@

all:		${NAME}

clean:
			rm -f main.o ft_tail2.o 

fclean:		clean
				rm -f ft_tail

re:			clean all

.PHONY:		all clean fclean re
