#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int i;

    va_start(args, format);

    // Loop through each character in the format string
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;  // Skip the '%' character

            if (format[i] == 'c') {
                char c = va_arg(args, int);  // Get the next argument as a char
                putchar(c);
                count++;
            }
            else if (format[i] == 's') {
                char *s = va_arg(args, char *);  // Get the next argument as a string
                fputs(s, stdout);
                count += strlen(s);
            }
            // Add more format specifiers here if needed
        } else {
            putchar(format[i]);
            count++;
        }
    }

    va_end(args);
    return count;
}

