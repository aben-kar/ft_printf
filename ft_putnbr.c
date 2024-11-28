/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:57:33 by acben-ka          #+#    #+#             */
/*   Updated: 2024/11/28 12:11:35 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
    count += ft_putchar(nb % 10 + '0');
    return (count);
}

int ft_putunbr(unsigned int n)
{
    int count;

    count = 0;
    if (n > 9)
        count += ft_putunbr(n / 10);
    count += ft_putchar(n % 10 + '0');
    return (count);
}

int ft_puthex(char c, unsigned int n)
{
    int     count;
    char    *hex;

    count = 0;
    if (c == 'x')
        hex = "0123456789abcdef";
    else
        hex = "0123456789ABCDEF";
    if (n >= 16)
        count += ft_puthex(c, n / 16);
    count += ft_putchar(hex[n % 16]);
    return (count);
}
