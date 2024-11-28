/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:18:15 by acben-ka          #+#    #+#             */
/*   Updated: 2024/11/28 20:26:31 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex(c, va_arg(args, unsigned int));
	else if (c == 'p')
		count += check_address((unsigned long)va_arg(args, void *));
	else if (c == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && check_format(*(format + 1)))
		{
			format++;
			if (!(*format))
				return (-1);
			count += ft_format(args, *format);
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
	ft_printf("%d\n", ft_printf("%c%s%p%d%i%u%x%X%", 48, "hello", (void *)0, INT_MAX, INT_MIN, UINT_MAX, 42, 42));
	printf("%d\n", printf("%c%s%p%d%i%u%x%X%", 48, "hello", (void *)0, INT_MAX, INT_MIN, UINT_MAX, 42, 42));
}