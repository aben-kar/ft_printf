/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:57:23 by acben-ka          #+#    #+#             */
/*   Updated: 2024/11/28 12:06:24 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putaddr(unsigned long n)
{
    int     count;
    char    *hex;

    count = 0;
    hex = "0123456789abcdef";
    if (n >= 16)
        count += ft_putaddr(n / 16);
    count += ft_putchar(hex[n % 16]);
    return (count);
}

int check_address(unsigned long n)
{
    int count;

    count = 0;
    if (!n)
        return (ft_putstr("(nil)"));
    count += ft_putstr("0x");
    count += ft_putaddr(n);
    return (count);
}
