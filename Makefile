NAME = push_swap.a
PNAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP_SRC =	ft_split.c push.c reverse.c rotate.c swap.c \
				sorting.c sort_0_6.c moves.c get_rotations.c ft_atoi.c

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRC:.c=.o)

all: $(PNAME)

$(PNAME): $(NAME)
	cc $(CFLAGS) push_swap.c $(NAME) -o $(PNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(PUSH_SWAP_OBJS)
	ar rcs $(NAME) $(PUSH_SWAP_OBJS)

clean:
	rm -f $(PUSH_SWAP_OBJS)

fclean: clean
	rm -f $(NAME) $(PNAME)

re: fclean all

.PHONY: clean fclean re all