NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_SRC =printf/ft_printf.c printf/ft_putchar_fd.c printf/ft_putstr_fd.c printf/ft_putnbr_fd.c \
			printf/ft_putunbr_fd.c printf/ft_putbase16_fd.c printf/ft_putaddress_fd.c

PUSH_SWAP_SRC =	push.c reverse.c rotate.c swap.c sorting.c

PRINTF_OBJS = $(PRINTF_SRC:.c=.o)

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRC:.c=.o)

all: $(NAME)

%.O: %.C
	$(CC) $(CFLAGS) -c $< -O $@

$(NAME): $(PUSH_SWAP_OBJS) $(PRINTF_OBJS)
	ar rcs $(NAME) $(PUSH_SWAP_OBJS) $(PRINTF_OBJS)

clean:
	rm -f $(PRINTF_OBJS) $(PUSH_SWAP_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all