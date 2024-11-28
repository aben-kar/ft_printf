#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

char	*ft_strchr(const char *str, int c)
{
	while (str && *str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == '\0' && (char)c == '\0')
		return ((char *)str);
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	check_format(char c)
{
	char	*flags;

	flags = "cspdiuxX%";
	if (ft_strchr(flags, c))
		return (1);
	return (0);
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

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	count = ft_strlen(s);
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	return (count);
}

int	ft_puthexa(unsigned int nb, char c)
{
	char	*hexa;
	int		count;

	count = 0;
	if (c == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (nb > 15)
		count += ft_puthexa(nb / 16, c);
	count += ft_putchar(hexa[nb % 16]);
	return (count);
}

int	ft_putadr(unsigned long n)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = "0123456789abcdef";
	if (n > 15)
		count += ft_putadr(n / 16);
	count += ft_putchar(ptr[n % 16]);
	return (count);
}

int	check_pointer(unsigned long n)
{
	int				count;
	unsigned long	nb;

	nb = n;
	count = 0;
	if ((void *)nb == (void *)0)
		return (ft_putstr("0x0"));
	count += ft_putstr("0x");
	return (count += ft_putadr(nb));
}

int	ft_putnbr(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	count += ft_putchar(nb % 10 + '0');
	return (count);
}


int	ft_process_args(va_list arg, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(arg, int));
	else if (c == 's')
	{
		count = ft_putstr(va_arg(arg, char *));
	}
	else if (c == 'p')
	{
		count += check_pointer(va_arg(arg, unsigned long));
	}
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		count = ft_putunbr(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_puthexa(va_arg(arg, unsigned int), c);
	else
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%' && check_format(*(format + 1)))
		{
			format++;
			count += ft_process_args(arg, *format);
		}
		else
			count += ft_putchar(*format);
		if (!(*format))
			break ;
		format++;
	}
	va_end(arg);
	return (count);
}

int main (void)
{
    printf("a % b\n");	// char 			c = 'a';
	// char 			s[] = "TESST 1337 42 smaurai0lava";
	// int 			max = 2147483647;
	// int 			min = -2147483648;
	// int 			nul = 0;
	// unsigned int 	ui = 1337;
	// unsigned int 	nui = -5;
	// char 			*p = &c;
	// int 			*pt = &min;
	// long 			max_l = LONG_MAX;
	// long 			min_l = LONG_MIN;
	// int				nbr; 
	// int				num;

	// nbr = 0;
	// num = 0;

	// ft_printf("\n***************--  my printf: --**************\n");
	// nbr += ft_printf("character :      %c\n", c);
	// nbr += ft_printf("string :         %s\n", s);
	// nbr += ft_printf("decimal max :    %d\n", max);
	// nbr += ft_printf("integer min :    %i\n", min);
	// nbr += ft_printf("unsigned :       %u\n", ui);
	// nbr += ft_printf("unsigned neg :   %u\n", nui);
	// nbr += ft_printf("pointer of char: %p\n", p);
	// nbr += ft_printf("pointer of min : %p\n", pt);
	// nbr += ft_printf("null in hex :    %x\n", nul);
	// nbr += ft_printf("max in hex :     %X\n", max);
	// nbr += ft_printf("                 %%\n");
	// nbr += ft_printf("POINTER LONG     %p\n%p\n", &min_l, &max_l);
	// nbr += ft_printf("                 %p\n", (void *)-14523);
	// nbr += ft_printf("0x               %p-\n", (void *)ULONG_MAX);
	// nbr += ft_printf("                 %pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	// nbr += ft_printf("S4%Xf`<f$J '%X@%i!EAsCK4%xy_%d)-7l3Mjln%pf1+q6%%%Xo{{ulxmt%i{dNsv4A<0%X`f}Qf\n", -1471565265, -1471859136, 1415328167, -11470702, 240168234, (void *)-1415595296739750836, -1039313513, 1875270030, -707402165);

	// printf("\n**************-- original printf: --***************\n");
	// num += printf("character :      %c\n", c);
	// num += printf("string :         %s\n", s);
	// num += printf("decimal max :    %d\n", max);
	// num += printf("integer min :    %i\n", min);
	// num += printf("unsigned :       %u\n", ui);
	// num += printf("unsigned neg :   %u\n", nui);
	// num += printf("pointer of char: %p\n", p);
	// num += printf("pointer of min : %p\n", pt);
	// num += printf("null in hex :    %x\n", nul);
	// num += printf("max in hex :     %X\n", max);
	// num += printf("                 %%\n");
	// num += printf("POINTER LONG     %p\n%p\n", &min_l, &max_l);
	// num += printf("                 %p\n", (void *)-14523);
	// num += printf("0x               %p-\n", (void *)ULONG_MAX);
	// num += printf("                 %pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	// num += printf("S4%Xf`<f$J '%X@%i!EAsCK4%xy_%d)-7l3Mjln%pf1+q6%%%Xo{{ulxmt%i{dNsv4A<0%X`f}Qf\n", -1471565265, -1471859136, 1415328167, -11470702, 240168234, (void *)-1415595296739750836, -1039313513, 1875270030, -707402165);

	// ft_printf("\n**************-- return values --******************\n");
	// printf("my printf :           %d\n", nbr);
	// printf("original printf :     %d\n", num);
}