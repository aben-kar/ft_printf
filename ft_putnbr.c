#include "libftprintf.h"

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

int ft_putaddr(unsigned long n)
{
    int count;
    char *hex;

    count = 0;
    hex = "0123456789abcdef";
    if (n >= 16)
        count += ft_putaddr(n / 16);
    count += ft_putchar(hex[n % 16]);
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

int check_address(unsigned long n)
{
    int count;

    if ((void *)n == (void *)0)
        return (ft_putstr("0x0"));
    count = 0;
    count += ft_putstr("0x");
    return (count += ft_putaddr(n));
}

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
// int main()
// {
//     int i = 16;
//     // ft_puthex(&i);
//     printf ("%x", i);
// }