#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
  *
  *
  *
  *
  *
  */
int _printf(const char *format, ...) 
{
	va_list args;
	int count = 0;
	va_start(args, format);

    
	while (*format != '\0') {
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += print_char(va_arg(args, int));
					break;
				case 's':
					count += print_str(va_arg(args, char *));
					break;
				case '%':
					count += print_percent();	
					break;
				default:
					_putchar('%');
					_putchar(*format);
					break;
			}
		}
		else
			_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
