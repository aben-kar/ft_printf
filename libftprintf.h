#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>


int ft_putchar(char c);
int ft_putnbr(long nb);
int ft_putstr(char *str);
int ft_puthex(char c, int n);
int check_address(unsigned long n);

#endif