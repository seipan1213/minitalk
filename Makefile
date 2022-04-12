NAME		=	minitalk
SRCSDIR		=	./srcs

CLIENT_NAME	=	client
SERVER_NAME	=	server
CLIENT_SRCS	=	${SRCSDIR}/client.c ${SRCSDIR}/utils.c
CLIENT_OBJS	=	${CLIENT_SRCS:.c=.o}
SERVER_SRCS	=	${SRCSDIR}/server.c ${SRCSDIR}/utils.c
SERVER_OBJS	=	${SERVER_SRCS:.c=.o}


CLIENT_NAME_BONUS	=	client_bonus
SERVER_NAME_BONUS	=	server_bonus
CLIENT_SRCS_BONUS	=	${SRCSDIR}/client_bonus.c ${SRCSDIR}/client_sub_bonus.c ${SRCSDIR}/utils_bonus.c
CLIENT_OBJS_BONUS	=	${CLIENT_SRCS_BONUS:.c=.o}
SERVER_SRCS_BONUS	=	${SRCSDIR}/server_bonus.c ${SRCSDIR}/utils_bonus.c
SERVER_OBJS_BONUS	=	${SERVER_SRCS_BONUS:.c=.o}

INCLUDES	=	-I ./includes -I ${LIBFTDIR}
LIBFTDIR	=	./libft
LIBFT		=	${LIBFTDIR}/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

${NAME}: ${CLIENT_NAME} ${SERVER_NAME}

bonus: ${CLIENT_NAME_BONUS} ${SERVER_NAME_BONUS}

all: ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${CLIENT_NAME}: ${CLIENT_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${CLIENT_OBJS} ${LIBFT} ${INCLUDES} -o $@

${SERVER_NAME}: ${SERVER_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${SERVER_OBJS} ${LIBFT} ${INCLUDES} -o $@


${CLIENT_NAME_BONUS}: ${CLIENT_OBJS_BONUS} ${LIBFT}
	${CC} ${CFLAGS} ${CLIENT_OBJS_BONUS} ${LIBFT} ${INCS} -o $@

${SERVER_NAME_BONUS}: ${SERVER_OBJS_BONUS} ${LIBFT}
	${CC} ${CFLAGS} ${SERVER_OBJS_BONUS} ${LIBFT} ${INCS} -o $@

.c.o:
	${CC} ${CFLAGS} $< -c ${INCLUDES} -o $@

clean:
	rm -f ${CLIENT_OBJS} ${SERVER_OBJS} ${CLIENT_OBJS_BONUS} ${SERVER_OBJS_BONUS}
	${MAKE} clean -C ${LIBFTDIR}

fclean: clean
	rm -f ${CLIENT_NAME} ${SERVER_NAME} ${CLIENT_NAME_BONUS} ${SERVER_NAME_BONUS}
	${MAKE} fclean -C ${LIBFTDIR}

re: fclean all

.PHONY: all bonus clean fclean re