CS			= funcs.c ft_printf.c

BS 			= bonus.c

SRCS 		= $(addprefix ./src/, $(CS))

BNS 		= $(addprefix ./bonus/, $(BS)) 

OBJS		= ${SRCS:.c=.o}

B_OBJS 		= ${BNS:.c=.o}

NAME		= libftprintf.a

CFLAGS		= -Wall -Wextra -Werror -I ./

all:		${NAME}

bonus : 	${NAME} ${B_OBJS}
			ar -rcs $(NAME) $^ libft/libft.a;\
			mv $^ ./objs/
			

${NAME}:	${OBJS}
			make -C ./libft;\
			cp libft/libft.a $@;\
			ar -rcs $@ $^ ;\
			mv $^ ./objs/;

.c.o:
			gcc ${CFLAGS} -c $<  -o ${<:.c=.o}

clean:		
			rm -f $(addprefix ./objs/,${CS:.c=.o})
				

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re test bonus

# .SILENT: 
# 			re check $(NAME) all