/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:57:41 by acben-ka          #+#    #+#             */
/*   Updated: 2024/11/28 12:05:19 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

int     ft_putchar(char c);
int     ft_putnbr(long nb);
int     ft_putstr(char *str);
int     ft_puthex(char c, unsigned int n);
int     check_address(unsigned long n);
int     ft_putunbr(unsigned int n);
int     ft_putaddr(unsigned long n);
int     ft_printf(const char *format, ...);
char    *ft_strchr(const char *str, int c);
int     check_format(char f);
int     ft_format(va_list args, char c);

#endif
