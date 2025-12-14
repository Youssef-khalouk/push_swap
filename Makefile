NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP_SRC =	ft_split.c push.c reverse.c rotate.c swap.c sorting.c moves.c get_rotations.c

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(PUSH_SWAP_OBJS)
	ar rcs $(NAME) $(PUSH_SWAP_OBJS)

clean:
	rm -f $(PUSH_SWAP_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all