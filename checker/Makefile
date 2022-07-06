SRCS    = checker.c ft_check.c ft_create_lst.c ft_isdigit.c get_next_line.c movimientos.c push_swap_utils.c push_swap_utils2.c get_next_line_utils.c trasform_numbers.c

OBJS	= ${SRCS:.c=.o}

NAME	= checker

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address

LIBFT = ../libft/libft.a

PATHLIB = ../libft/

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${LIBFT} ${OBJS}
				${CC} ${CFLAGS} ${LIBFT} ${OBJS} -o ${NAME}

${LIBFT}:
			@make -C ${PATHLIB}

all:		${NAME}

clean:
				@make clean -C ${PATHLIB}
				${RM} ${OBJS} ${OBJB}

fclean: 	clean
				@make fclean -C ${PATHLIB}
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re 