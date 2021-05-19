SRCS	= ./main.c ./print_success.c ./testft_strlen.c ./testft_memset.c \
		  ./testft_bzero.c ./testft_memcpy.c

OBJS	= ${SRCS:.c=.o}

NAME	= main

CFLAGS	= -Wall -Werror -Wextra -g

RM		= rm -f
CC		= gcc ${CFLAGS}

all: libs ${NAME}

${NAME}: ${OBJS} libft/libft.a
	${CC} -o ${NAME} ${OBJS} -L./libft -lft

${OBJS}: ${SRCS}
	${CC} -c ${SRCS}

libs:
	${MAKE} -C libft/

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
