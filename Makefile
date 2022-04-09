NAME		=	minitalk
CLIENT_NAME	=	client
SERVER_NAME	=	server
SRCSDIR		=	./srcs
SERVER_SRCS	=	${SRCSDIR}/server.c ${SRCSDIR}/utils.c
SERVER_OBJS	=	${SERVER_SRCS:.c=.o}
CLIENT_SRCS	=	${SRCSDIR}/client.c ${SRCSDIR}/utils.c
CLIENT_OBJS	=	${CLIENT_SRCS:.c=.o}
INCLUDES	=	-I ./includes -I ${LIBFTDIR}
LIBFTDIR	=	./libft
LIBFT		=	${LIBFTDIR}/libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

${NAME}: ${CLIENT_NAME} ${SERVER_NAME}

all: ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${CLIENT_NAME}: ${CLIENT_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${CLIENT_OBJS} ${LIBFT} ${INCLUDES} -o $@

${SERVER_NAME}: ${SERVER_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${SERVER_OBJS} ${LIBFT} ${INCLUDES} -o $@

.c.o:
	${CC} ${CFLAGS} $< -c ${INCLUDES} -o $@

clean:
	rm -f ${CLIENT_OBJS} ${SERVER_OBJS} ${CLIENT_BONUS_OBJS} ${SERVER_BONUS_OBJS}
	${MAKE} clean -C ${LIBFTDIR}

fclean: clean
	rm -f ${CLIENT_NAME} ${SERVER_NAME} ${CLIENT_BONUS_NAME} ${SERVER_BONUS_NAME}
	${MAKE} fclean -C ${LIBFTDIR}

re: fclean all

.PHONY: all bonus clean fclean re