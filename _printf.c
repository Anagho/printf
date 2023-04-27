#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int num_chars_printed = 0;
    char c;
    while ((c = *format++) != '\0') {
        if (c == '%') {
            c = *format++;
            if (c == 'c') {
                // Print a character
                char ch = (char) va_arg(args, int);
                putchar(ch);
                num_chars_printed++;
            } else if (c == 's') {
                // Print a string
                char *str = va_arg(args, char *);
                while (*str != '\0') {
                    putchar(*str++);
                    num_chars_printed++;
                }
            } else if (c == '%') {
                // Print a percent symbol
                putchar('%');
                num_chars_printed++;
            } else {
                // Unknown conversion specifier
                putchar('%');
                putchar(c);
                num_chars_printed += 2;
            }
        } else {
            // Just print the character
            putchar(c);
            num_chars_printed++;
        }
    }
    
    va_end(args);
    
    return num_chars_printed;
}
