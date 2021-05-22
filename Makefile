SRCS	= ./main.c ./utils/print_success.c ./utils/explain_errors.c \
		  ./testft_strlen.c ./testft_memset.c ./testft_bzero.c \
		  ./testft_memcpy.c ./testft_memccpy.c ./testft_memmove.c \
		  ./testft_memchr.c ./testft_memcmp.c  ./testft_strlcpy.c \
		  ./testft_strlcat.c ./testft_strchr.c ./testft_strrchr.c \
		  ./testft_strnstr.c ./testft_strncmp.c ./testft_atoi.c \
		  ./testft_isspace.c ./testft_isalpha.c ./testft_isdigit.c \
		  ./testft_isalnum.c ./testft_isascii.c ./testft_isprint.c \
		  ./testft_toupper.c ./testft_tolower.c

OBJS	= ${SRCS:.c=.o}

NAME	= main

CFLAGS	= -Wall -Werror -Wextra

UNAME	= $(shell uname)
ifeq (${UNAME}, Linux)
${NAME}: CFLAGS := ${CFLAGS}
endif

RM		= rm -f
CC		= clang ${CFLAGS}

all: libs ${NAME}

${NAME}: ${OBJS} libft/libft.a
	${CC} ${OBJS} -o ${NAME} -lbsd -L./libft -lft

%.o: %.c
	${CC} -c $< -o $@

libs:
	${MAKE} -C libft/

_sanitize: CFLAGS := ${CFLAGS} -fsanitize=address -g
_sanitize:
	${MAKE} fclean -C libft/
	${MAKE} CFLAGS="${CFLAGS}" -C libft/

test: CC		:= ${CC} -fsanitize=address -g
test: _sanitize ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	make fclean -C libft
	${RM} ${NAME}

re: fclean all

.PHONY: re fclean clean test _sanitize libs
