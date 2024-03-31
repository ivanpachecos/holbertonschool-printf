#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
	{
            format++;
            if (*format == 'c')
	    {
                char c = (char) va_arg(args, int);
                _putchar(c);
                count++;
            }
	    else if (*format == 's')
	    {
                char *str = va_arg(args, char *);
                while (*str) {
                    _putchar(*str++);
                    count++;
                }
            }
	    else if (*format == '%')
	    {
                _putchar('%');
                count++;
            }
        }
	else
	{
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}
