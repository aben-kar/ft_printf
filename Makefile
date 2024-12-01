NAME    = libftprintf.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SRCS    = ft_putchar.c ft_putnbr.c ft_putaddr.c ft_printf.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
