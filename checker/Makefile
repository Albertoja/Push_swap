SRCS    = checker.c ft_check.c ft_create_lst.c ft_isdigit.c get_next_line.c movimientos.c push_swap_utils.c push_swap_utils2.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

NAME = checker

LIBFT_PATH = ../libft/

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra #-g3 -fsanitize=address

RM = rm -f

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(LIBFT_PATH)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) --silent
	@$(CC) -o $(NAME) $? -I$(LIBFT_PATH) -L$(LIBFT_PATH) -lft
	@echo $(NAME)": ready to be executed"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean --silent

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean --silent

re: fclean $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) clean --silent

.PHONY: all clean fclean re