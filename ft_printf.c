#include "libftprintf.h"

int ft_format(va_list args, char c)
{
    int count;

    count = 0;
    if (c == 'c')
        count += ft_putchar(va_arg(args, int));
    else if (c == 's')
        count += ft_putstr(va_arg(args, char *));
    else if (c == 'd' || c == 'i')
        count += ft_putnbr(va_arg(args, int));
    else if (c == 'x' || c == 'X')
        count += ft_puthex(c, va_arg(args, int));
    else if (c == 'p')
        count += check_address((unsigned long)va_arg(args, void *));
    else if(c == 'u')
        count += ft_putunbr(va_arg(args, unsigned int));
    else
        count += ft_putchar('%');
    return (count);
}
int ft_printf(const char *format, ...)
{
    va_list argss;
    if (!format)
        return (-1);
    va_start(argss, format);
    int count;

    count = 0;
    while (*format)
    {
        if (*format == '%' && check_fromat(*(format + 1)))
        {
            format++;
            count += ft_format(argss, *format);
        }
        else
            count += ft_putchar(*format);
        format++;
    }
    va_end(argss);
    return (count);
}

int main()
{
    char *str = "achraf pentoura";
    int x = 5;
    int *ptr = &x;
    ft_printf("%d\n", ft_printf("%c - %s - %p - %d - %i - %u - %x - %X\n",49,  str, ptr, INT_MAX, INT_MIN, UINT_MAX, 42, 42));
    printf("%d", printf("%c - %s - %p - %d - %i - %u - %x - %X\n",49,  str, ptr, INT_MAX, INT_MIN, UINT_MAX, 42, 42));

    // int i = 255;
    // ft_printf ("%p\n", &i);
    // printf ("%p", &i);
}
