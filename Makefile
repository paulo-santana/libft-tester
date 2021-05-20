SRCS	= ./main.c ./utils/print_success.c ./utils/explain_errors.c \
		  ./testft_strlen.c ./testft_memset.c ./testft_bzero.c \
		  ./testft_memcpy.c ./testft_memccpy.c ./testft_memmove.c \
		  ./testft_memchr.c ./testft_memcmp.c  ./testft_strlcpy.c \
		  ./testft_strlcat.c ./testft_strchr.c ./testft_strrchr.c

OBJS	= ${SRCS:.c=.o}

NAME	= main

CFLAGS	= -Wall -Werror -Wextra -lbsd -g

RM		= rm -f
CC		= gcc ${CFLAGS}

all: libs ${NAME}

${NAME}: ${OBJS} libft/libft.a
	${CC} -o ${NAME} ${OBJS} -L./libft -lft

libs:
	${MAKE} -C libft/

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
