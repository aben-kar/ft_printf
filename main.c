#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

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
    if (is_unsigned) {
        num = (unsigned long)nbr;
    } else {
        if (nbr < 0) {
            len += ft_putchar('-'); // Add '-' for negative numbers
            num = -nbr;
        } else {
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
 

// Pour comparaison avec printf standard
int main() {
    //int count;

    // Test %c - Caractère unique
    // ft_printf("%c", 'A');

    //Test %s - Chaîne de caractères
    //ft_printf("%s", "alic");

    // // Test %s avec NULL
    //ft_printf("%s", NULL);

    // // Test %p - Affichage de pointeur
    // int i = 42;
    // ft_printf("%p", &i);

    // // Test %d et %i - Entiers signés
    int j = 1242;
    ft_printf("%i\n", j);
    printf("%i", j);
    // // Test %u - Entiers non signés
    // count = ft_printf("Test %%u: [%u]\n", 4294967295U); // Valeur max pour unsigned int
    // printf("Expected: Test %%u: [4294967295]\n");
    // printf("Returned count: %d\n\n", count);

    // // Test %x et %X - Hexadécimal
    // count = ft_printf("Test %%x et %%X: [%x] [%X]\n", 255, 255);
    // printf("Expected: Test %%x et %%X: [ff] [FF]\n");
    // printf("Returned count: %d\n\n", count);

    // // Test %%
    // count = ft_printf("Test %%%%: [%%]\n");
    // printf("Expected: Test %%%%: [%%]\n");
    // printf("Returned count: %d\n\n", count);

    // // Test combinaison de tous les types
    // count = ft_printf("Combinaison: [%c] [%s] [%p] [%d] [%u] [%x] [%X] [%%%%]\n", 'Z', "Test String", &x, -2147483648, 12345U, 3735928559U, 3735928559U);
    // printf("Expected: Combinaison: [Z] [Test String] [%p] [-2147483648] [12345] [deadbeef] [DEADBEEF] [%%]\n", (void *)&x);
    // printf("Returned count: %d\n\n", count);

    // // Test format invalide
    // count = ft_printf("Test format invalide: [%y]\n");
    // printf("Expected: Test format invalide: []\n"); // Rien n'est imprimé pour %y (invalide)
    // printf("Returned count: %d\n\n", count);

    return 0;
}
