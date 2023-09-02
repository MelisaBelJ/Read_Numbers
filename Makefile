SRC	= main.c util.c print_nbr.c check.c read_nbr.c

SRCS	= ${addprefix ${PRE}, ${SRC}}

OBJS	= ${SRCS:.c=.o}

PRE	= ./srcs/

HEAD	= ./includes/

NAME	= read_numbers

all:	${NAME}

%.o:	%.c
	cc -Wall -Wextra -Werror -I ${HEAD} -c $*.c -o $*.o

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror -o $@ $^

clean:
	rm -fr ${OBJS}

fclean:		clean
	rm -fr ${NAME}

re:
	fclean all

.PHONY:		all clean fclean re
