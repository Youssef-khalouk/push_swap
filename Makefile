PRINTF = libft_printf.a
PUSH_SWAP = libft_push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_SRC =printf/ft_printf.c printf/ft_putchar_fd.c printf/ft_putstr_fd.c printf/ft_putnbr_fd.c \
			printf/ft_putunbr_fd.c printf/ft_putbase16_fd.c printf/ft_putaddress_fd.c

PUSH_SWAP_SRC =	push.c reverse.c rotate.c swap.c

PRINTF_OBJS = $(PRINTF_SRC:.c=.o)

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRC:.c=.o)

all: $(PRINTF) $(PUSH_SWAP)

%.O: %.C
	$(CC) $(CFLAGS) -c $< -O $@

$(PRINTF): $(PRINTF_OBJS)
	ar rcs $(PRINTF) $(PRINTF_OBJS)

$(PUSH_SWAP): $(PUSH_SWAP_OBJS)
	ar rcs $(PUSH_SWAP) $(PUSH_SWAP_OBJS)

clean:
	rm -f $(PRINTF_OBJS) $(PUSH_SWAP_OBJS)

fclean: clean
	rm -f $(PRINTF) $(PUSH_SWAP)

re: fclean all

.PHONY: clean fclean re all