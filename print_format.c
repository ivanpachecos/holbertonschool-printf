#include "main.h"
#include <stdlib.h>

/**
  * print_format - Prints a format
  * @format: The format to prints
  * @args: A list of variadic arguments
  * Return: The length of the format
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
			{
				count = _print_invalid_spec(format[index - 1], format[index], count);
			}
			else
			{
				count += _print_spec(format[index], args);
			}
		}
		else
		{
			count += _putchar(format[index]);
		}

		index++;
	}

	return (count);
}

/**
  * _print_spec - Prints a valid specifier
  * @format: The specifier to prints
  * @args: A list of variadic arguments
  *
  * Return: The length of the specifier
  */
int _print_spec(char format, va_list args)
{
	int index  = 0, length = 0;
	fmt_spc f_list[] = {
		{"c", print_char},
		{"s", _print_a_string},
		{"d", _print_a_integer},
		{"index", _print_a_integer},
		{NULL, NULL}
	};

	while (f_list[index].specifier)
	{
		if (*f_list[index].specifier == format)
			length = f_list[index].f(args);

		index++;
	}

	return (length);
}

/**
  * _print_invalid_spec - Prints a invalid specifier
  * @prev_format: The previous specifier of actual specifier
  * @format: The specifier to prints
  * @count: The current count before prints invalid specifiers
  *
  * Return: The current count after prints invalid specifiers
  */
int _print_invalid_spec(char prev_format, char format, int count)
{
	count += _putchar('%');

	if (prev_format == ' ')
	{
		count += _putchar(' ');
		count += _putchar(format);
	}
	else
	{
		count += _putchar(format);
	}

	return (count);
}

/**
  * _validate_char - validate the type
  * @_type: character to be comparate
  *
  * Return: 1 if char is equal to a type
  */
int _validate_char(char _type)
{
	char f_list[] = {'c', 's', 'd', 'i', 'b', '%'};
	int i = 0;

	while (f_list[i])
	{
		if (f_list[i] == _type)
			return (1);
		i++;
	}
	return (0);
}
