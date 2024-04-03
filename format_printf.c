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
			else
			{
				if (!_print_spec(format[index], args))
					count = _print_invalid_spec(format[index - 1], format[index], count);
			}
		}
		else
			count += _putchar(format[index]);

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
    int index;

	fmt_spc f_list[] = {
		{"c", print_char},
		{"s", _print_a_string},
		{"d", _print_a_integer},
		{"i", _print_a_integer},
		{NULL, NULL}
	};

	for (index = 0; f_list[index].specifier; index++)
	{
		if (*f_list[index].specifier == format)
			return f_list[index].f(args);
	}

	return 0;
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
  * @char_to_compare: character to be compared
  *
  * Return: 1 if char is equal to a type
  */
int _validate_char(char char_to_compare)
{
	const char *valid_formats = "csdi%";
	return (strchr(valid_formats, char_to_compare) != NULL);
}
