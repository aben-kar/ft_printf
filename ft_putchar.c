/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:57:27 by acben-ka          #+#    #+#             */
/*   Updated: 2024/11/28 12:07:44 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
    int i;
    int len;

    if (!str)
        return (ft_putstr("(null)"));
    i = 0;
    len = 0;
    while (str[i])
    {
        len += write(1, &str[i], 1);
        i++;
    }
    return (len);
}

char *ft_strchr(const char *str, int c)
{
    if (!str)
        return (NULL);
    while (*str)
    {
        if ((char)c == *str)
            return ((char *)str);
        str++;
    }
    if ((char)c == '\0')
        return ((char *)str);
    return (NULL);
}

int check_format(char f)
{
    char *find;

    find = "csdixXup%";
    if (ft_strchr(find, f))
        return (1);
    return (0);
}
