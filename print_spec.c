#include "main.h"

/**
  * _print_spec - Prints a valid specifier
  * @format: The specifier to prints
  * @args: A list of variadic arguments
  *
  * Return: The length of the specifier
  */

int _print_spec(char format, va_list args)
{
	int index  = 0;
	fmt_spc f_list[] = {
		{"c", print_char},
		{"s", _print_a_string},
		{"d", _print_a_integer},
		{"i", _print_a_integer},
		{NULL, NULL}
	};

	while (f_list[index].specifier)
	{
		if (*f_list[index].specifier == format)
			return (f_list[index].f(args));

		index++;
	}

	return (0);
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
	char f_list[] = {'c', 's', 'd', 'i', '%'};
	int i = 0;

	while (f_list[i])
	{
		if (f_list[i] == _type)
			return (1);
		i++;
	}
	return (0);
}
