#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/* Declare the checkSpecifier function prototype */
int checkSpecifier(const char *format, int i, va_list arglist);

int _printf(const char *format, ...)
{
    va_list arglist;
    int count = 0, i;

    va_start(arglist, format);  /* Start variadic arguments */

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')  /* Check for a format specifier */
        {
            count += checkSpecifier(format, i, arglist); /* Process specifier */
        }
        else
        {
            write(1, &format[i], 1);  /* Print character */
            count++;
        }
    }

    va_end(arglist);  /* Clean up the variadic arguments */
    return count;
}
