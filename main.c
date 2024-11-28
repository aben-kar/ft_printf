#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

// Function to print a character
int ft_putchar(char c) {
    return write(1, &c, 1);
}

// Function to print a string
int ft_putstr(char *s) {
    int len = 0;
    if (!s)
        s = "(null)"; // If the string is NULL, print "(null)"
    while (*s) {
        ft_putchar(*s);
        s++;
        len++;
    }
    return len;
}

// Function to convert and print a number in a given base
int ft_putnbr_base(long nbr, char *base, int is_unsigned) {
    int len = 0;
    unsigned long num;

    // Check if the number is unsigned
    if (is_unsigned) 
    {
        num = (unsigned long)nbr;
    } 
    else 
    {
        if (nbr < 0) 
        {
            len += ft_putchar('-'); // Add '-' for negative numbers
            num = -nbr;
        } 
        else 
        {
            num = nbr;
        }
    }
    // Calculate the length of the base
    int base_len = 0;
    while (base[base_len]) {
        base_len++;
    }

    // Recursive conversion and display
    if (num >= (unsigned long)base_len) {
        len += ft_putnbr_base(num / base_len, base, 1);
    }
    len += ft_putchar(base[num % base_len]);

    return len;
}

// Function to print a signed integer
int ft_putnbr(int n) {
    return ft_putnbr_base(n, "0123456789", 0);
}

// Function to print an unsigned integer
int ft_putnbr_unsigned(unsigned int n) {
    return ft_putnbr_base(n, "0123456789", 1);
}

// Function to print a pointer in hexadecimal
int ft_puthex(unsigned long ptr, char *base) {
    int len = ft_putstr("0x");
    return len + ft_putnbr_base(ptr, base, 1);
}

// Main printf-like function
int ft_printf(const char *format, ...) {
    va_list args;
    int char_count = 0;

    va_start(args, format);
    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'c')      // %c: Print a character
                char_count += ft_putchar(va_arg(args, int));
            else if (*format == 's') // %s: Print a string
                char_count += ft_putstr(va_arg(args, char *));
            else if (*format == 'p') // %p: Print a pointer in hexadecimal
                char_count += ft_puthex((unsigned long)va_arg(args, void *), "0123456789abcdef");
            else if (*format == 'd' || *format == 'i') // %d or %i: Print a signed integer
                char_count += ft_putnbr(va_arg(args, int));
            else if (*format == 'u') // %u: Print an unsigned integer
                char_count += ft_putnbr_unsigned(va_arg(args, unsigned int));
            else if (*format == 'x') // %x: Print a number in hexadecimal (lowercase)
                char_count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", 1);
            else if (*format == 'X') // %X: Print a number in hexadecimal (uppercase)
                char_count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", 1);
            else if (*format == '%') // %%: Print a '%' sign
                char_count += ft_putchar('%');
        } else {
            char_count += ft_putchar(*format);
        }
        format++;
    }
    va_end(args);

    return char_count;
}

int main (void)
{
	char 			c = 'a';
	char 			s[] = "TESST 1337 42 smaurai0lava";
	int 			max = 2147483647;
	int 			min = -2147483648;
	int 			nul = 0;
	unsigned int 	ui = 1337;
	unsigned int 	nui = -5;
	char 			*p = &c;
	int 			*pt = &min;
	long 			max_l = LONG_MAX;
	long 			min_l = LONG_MIN;
	int				nbr; 
	int				num;

	nbr = 0;
	num = 0;

	ft_printf("\n***************--  my printf: --**************\n");
	nbr += ft_printf("character :      %c\n", c);
	nbr += ft_printf("string :         %s\n", s);
	nbr += ft_printf("decimal max :    %d\n", max);
	nbr += ft_printf("integer min :    %i\n", min);
	nbr += ft_printf("unsigned :       %u\n", ui);
	nbr += ft_printf("unsigned neg :   %u\n", nui);
	nbr += ft_printf("pointer of char: %p\n", p);
	nbr += ft_printf("pointer of min : %p\n", pt);
	nbr += ft_printf("null in hex :    %x\n", nul);
	nbr += ft_printf("max in hex :     %X\n", max);
	nbr += ft_printf("                 %%\n");
	nbr += ft_printf("POINTER LONG     %p\n%p\n", &min_l, &max_l);
	nbr += ft_printf("                 %p\n", (void *)-14523);
	nbr += ft_printf("0x               %p-\n", (void *)ULONG_MAX);
	nbr += ft_printf("                 %pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	nbr += ft_printf("S4%Xf`<f$J '%X@%i!EAsCK4%xy_%d)-7l3Mjln%pf1+q6%%%Xo{{ulxmt%i{dNsv4A<0%X`f}Qf\n", -1471565265, -1471859136, 1415328167, -11470702, 240168234, (void *)-1415595296739750836, -1039313513, 1875270030, -707402165);

	printf("\n**************-- original printf: --***************\n");
	num += printf("character :      %c\n", c);
	num += printf("string :         %s\n", s);
	num += printf("decimal max :    %d\n", max);
	num += printf("integer min :    %i\n", min);
	num += printf("unsigned :       %u\n", ui);
	num += printf("unsigned neg :   %u\n", nui);
	num += printf("pointer of char: %p\n", p);
	num += printf("pointer of min : %p\n", pt);
	num += printf("null in hex :    %x\n", nul);
	num += printf("max in hex :     %X\n", max);
	num += printf("                 %%\n");
	num += printf("POINTER LONG     %p\n%p\n", &min_l, &max_l);
	num += printf("                 %p\n", (void *)-14523);
	num += printf("0x               %p-\n", (void *)ULONG_MAX);
	num += printf("                 %pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	num += printf("S4%Xf`<f$J '%X@%i!EAsCK4%xy_%d)-7l3Mjln%pf1+q6%%%Xo{{ulxmt%i{dNsv4A<0%X`f}Qf\n", -1471565265, -1471859136, 1415328167, -11470702, 240168234, (void *)-1415595296739750836, -1039313513, 1875270030, -707402165);

	ft_printf("\n**************-- return values --******************\n");
	printf("my printf :           %d\n", nbr);
	printf("original printf :     %d\n", num);
}
