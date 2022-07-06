SRCS	= main.c push_swap_utils.c push_swap_utils2.c movimientos.c sort_undo_five.c ft_check.c algorithm.c trasform_numbers.c ft_create_lst.c basic_utils.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

LIBFT_PATH = ./libft/

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

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