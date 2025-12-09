
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putunbr_fd.c ft_putbase16_fd.c ft_putaddress_fd.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.O: %.C
	$(CC) $(CFLAGS) -c $< -O $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all