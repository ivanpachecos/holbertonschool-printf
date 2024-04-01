#include "main.h"

/**
  * print_format - Prints a format
  * @format: The format to prints
  * @args: A list of variadic arguments
  * Return: The length of the format
  *
  */

int print_format(const char *format, va_list args)
{
	int count = 0;
	int index = 0;

	while (format && format[index])
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == '\0')
				return (-1);

			index++;

			while (format[index] == ' ')
				index++;

			if (format[index] == '%')
				count += _putchar(format[index]);

			if (_validate_char(format[index]) == 0)
				count = _print_invalid_spec(format[index - 1], format[index], count);
			else
				count += _print_spec(format[index], args);
		}
		else
			count += _putchar(format[index]);

		index++;
	}

	return (count);
}
