SRSC		= bsq_analis.c bsq_chek.c bsq_main.c bsq_print.c bsq_chek2.c bsq_chek3.c

OBJO		= ${SRSC:.c=.o}

NAME		= BSQ

GCC			= gcc

RM			= rm -f

FLAG		= -Wall -Wextra -Werror

.c.o:
			${GCC} ${FLAG} -c $< -o ${<:.c=.o}

${NAME}:	${OBJO}
			${GCC} ${FLAG} -o ${NAME} ${OBJO}

all:		${NAME}

clean:
			${RM} ${OBJO}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean
