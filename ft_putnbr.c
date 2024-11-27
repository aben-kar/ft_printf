#include "libftprintf.h"

int ft_putnbr(long nb)
{
    int count;

    count = 0;
    if (nb < 0)
    {
        count += ft_putchar('-');
        nb = -nb;
    }
    if (nb > 9)
        count += ft_putnbr(nb / 10);
    count += ft_putchar(nb % 10 + 48);
    return (count);
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}
int ft_puthex(char c, int n)
{
    int count;

    count = 0;
    char *hex;
    if (c == 'x')
        hex = "0123456789abcdef";
    else
        hex = "0123456789ABCDEF";
    if (n >= 16)
        count += ft_puthex(c, n / 16);
    count += ft_putchar(hex[n % 16]);
    return (count);
}
