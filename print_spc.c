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
