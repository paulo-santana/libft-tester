SRCS	= ./main.c ./print_success.c ./testft_strlen.c ./testft_memset.c \
		  ./testft_bzero.c

OBJS	= ${SRCS:.c=.o}

LIBS	= ./libft/libft.a

NAME	= main

CFLAGS	= -Wall -Werror -Wextra -g

RM		= rm -f
CC		= gcc ${CFLAGS}

all: ${NAME}

${NAME}: ${OBJS} ${LIBS}
	${CC} -o ${NAME} ${OBJS} -L./libft -lft

${OBJS}: ${SRCS}
	${CC} -c ${SRCS}

${LIBS}: 
	make re -C ./libft

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
