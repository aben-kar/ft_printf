#include "libftprintf.h"

void ft_putnbr(int nb)
{
    if (nb == INT_MIN)
    {
        write (1, "-2147483648", 11);
        return ;
    }
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb > 9)
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar(nb % 10 + 48);
}
int main()
{
    ft_putnbr(214748364);
}