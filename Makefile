# Name of the executable or library
NAME = libftprintf.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = ft_putchar.c ft_putnbr.c ft_putaddr.c ft_printf.c

# Object files
OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^
	make clean

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
