BONUS 		= $(wildcard bonus/*.c)

SRCS		= $(wildcard src/*.c)

OBJS		=  ${SRCS:.c=.o}

BONUS_OBJS  = 	${BOTH:.c=.o}

NAME		= libft.a

CFLAGS		= -Wall -Wextra -Werror

.PHONY:		all clean fclean bonus

all:		${NAME}

${NAME}:	${OBJS}
			ar -rcs $@ $^

bonus: 	
			gcc ${CFLAGS} -c ${BONUS} ${SRCS}  ;ar -rcs ${NAME} ${BONUS_OBJS} 

.c.o:
			gcc ${CFLAGS} -c $< -o  ${@:.c = .o}  

clean:
			rm -f ${OBJS} ./*o

fclean:		clean
			rm -f ${NAME}

re:			fclean all
