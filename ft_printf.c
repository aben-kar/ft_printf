#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    if (!format)
        return (-1);
    va_start(args, format);
    int count;

    count = 0;
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
                count += ft_putchar(va_arg(args, int));
            else if (*format == 's')
                count += ft_putstr(va_arg(args, char *));
            else if (*format == 'd' || *format == 'i')
                count += ft_putnbr(va_arg(args, int));
            else if (*format == 'x' || *format == 'X')
                count += ft_puthex(*format, va_arg(args, int));
            else if (*format == 'p')
                count += check_address((unsigned long)va_arg(args, void *));
            else if (*format == 'u')
		        count += ft_putunbr(va_arg(args, unsigned int));
            else
                count += ft_putchar('%');
        }
        else
            count += ft_putchar(*format);
        format++;
    }
    va_end(args);
    return (count);
}

int main()
{
    // char *str = "achraf pentoura";
    // int x = 5;
    // int *ptr = &x;
    // ft_printf("%d\n", ft_printf("%c - %s - %p - %d - %i - %u - %x - %X\n",49,  str, ptr, INT_MAX, INT_MIN, UINT_MAX, 42, 42));
    // printf("%d", printf("%c - %s - %p - %d - %i - %u - %x - %X\n",49,  str, ptr, INT_MAX, INT_MIN, UINT_MAX, 42, 42));

    int i = 255;
    ft_printf ("%p\n", &i);
    printf ("%p", &i);
}
