#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    if (!format)
        return (-1);
    va_start(args, format);

    int count;

    count = 0;
    char *hex;
    while (*format)
    {
        if (*format == '%')
        {
            if (*(format + 1) == 'c')
            {
                format++;
                count += ft_putchar(va_arg(args, int));
            }
            else if (*(format + 1) == 's')
            {
                format++;
                count += ft_putstr(va_arg(args, char *));
            }
            else if (*(format + 1) == 'd' || *(format + 1) == 'i')
            {
                format++;
                count += ft_putnbr(va_arg(args, int));
            }
            else if (*(format + 1) == 'x' || *(format + 1) == 'X')
            {
                format++;
                count += ft_puthex(*format, va_arg(args, int));
            }
            else if (*(format + 1) == 'p')
            {
                format++;
                count += check_address((unsigned long)va_arg(args, void *));
            }
            else if (*(format + 1) == 'u')
            {
                format++;
		        count += ft_putunbr(va_arg(args, unsigned int));
            }
            else
            {
                format++;
                count += ft_putchar('%');
            }
        }
        else
            count += ft_putchar(*format);
        format++;
    }
    va_end(args);
    return (count);
    //printf("%d\n", count);
}

int main()
{
    int i = 16;
    ft_printf("%d\n", ft_printf("%p %% % \n", &i));
    printf("%d\n", printf("%p %% % \n", &i));
}