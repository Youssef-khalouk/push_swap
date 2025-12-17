PNAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP_SRC =	ft_split.c push.c reverse.c rotate.c swap.c \
				sorting.c sort_0_6.c moves.c get_rotations.c ft_atoi.c

PUSH_SWAP_BONUS_SRC =	push.c reverse.c rotate.c swap.c ft_split.c \
						ft_atoi.c check_bonus.c

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRC:.c=.o)

PUSH_SWAP_BONUS_OBJS = $(PUSH_SWAP_BONUS_SRC:.c=.o)

all: $(PNAME)

bonus: $(BONUS)

$(BONUS): $(PUSH_SWAP_BONUS_OBJS)
	cc $(CFLAGS) ft_checker_bonus.c $(PUSH_SWAP_BONUS_OBJS) -o $(BONUS)

$(PNAME): $(PUSH_SWAP_OBJS)
	cc $(CFLAGS) $(PUSH_SWAP_OBJS) push_swap.c -o $(PNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PUSH_SWAP_OBJS) $(PUSH_SWAP_BONUS_OBJS)

fclean: clean
	rm -f $(PNAME) $(BONUS)

re: fclean all

.PHONY: clean fclean re all