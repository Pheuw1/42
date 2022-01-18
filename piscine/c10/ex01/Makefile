SRCS		= main.c

OBJS		= ${SRCS:.c=.o}

NAME 		= ft_cat

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc -Wall -Wextra -Werror $^ -o $@

all:		${NAME}

clean:
			rm -f main.o 

fclean:		clean
				rm -f ft_cat

re:			clean all

.PHONY:		all clean fclean re
