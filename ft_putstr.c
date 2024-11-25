#include "libftprintf.h"

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
        len += write (1, &str[i], 1);
        i++;
    }
    return len;
} 
// int main()
// {
//     ft_putstr("alic");
// }