#include "main.h"

/**
  * print_format - Prints a format
  * @format: The format to prints
  * @args: A list of variadic arguments
  * Return: The length of the format
  */
int print_format(const char *format, va_list args)
{
	int count = 0;
	const char *next_specifier;

    while (*format)
    {
        if (*format == '%')
        {
            if (*(format + 1) == '%')
            {
                count += _putchar('%');
                format += 2;
                continue;
            }

            next_specifier = format + 1;

            while (*next_specifier && !_validate_char(*next_specifier))
                ++next_specifier;

            if (*next_specifier == '\0')
                return -1;

            count += _print_spec(*next_specifier, args);

            format = next_specifier + 1;
        }
        else
        {
            count += _putchar(*format);
            ++format;
        }
    }

    return count;
}
