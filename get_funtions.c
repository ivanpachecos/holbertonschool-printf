#include "main.h"

/**
 * print_char - Prints a character
 * @args: A list of variadic arguments
 * Return: The length of the character
 */

int print_char(va_list args)
{
	char character = va_arg(args, int);

	_putchar(character);
	return (1);
}

/**
 * _print_a_string - Prints a string
 * @args: A list of variadic arguments
 *
 * Return: The length of the string
 */
int _print_a_string(va_list args)
{
	char *str = va_arg(args, char *);
	int length = 0;

	if (str != NULL)
	{
		while (*str)
		{
			_putchar(*str);
			str++;
			length++;
		}
		return (length);
	}
	/*if el null print null*/
	_putchar('(');
	_putchar('n');
	_putchar('u');
	_putchar('l');
	_putchar('l');
	_putchar(')');
	return (6);
}

/**
 * _print_a_integer - Prints an integer
 * @args: A list of variadic arguments
 *
 * Return: The length of the integer's digit string
 */
int _print_a_integer(va_list args)
{
	int count = 1;
	int num = 0;
	unsigned int n = 0;

	n = va_arg(args, int);
	num = n;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		n = num;
		count++;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	_recursion_integer(num);
	return (count);
}

/**
 * _recursion_integer - Prints an integer recursively
 * @num: The integer to print
 *
 * Return: Nothing
 */
void _recursion_integer(int num)
{
	unsigned int digit;

	digit = num;
	if (digit / 10)
		_recursion_integer(digit / 10);
	_putchar(digit % 10 + '0');
}
