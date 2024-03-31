#include "main.h"

/**
 * func_d - add a value to buff
 * @buff: str var
 * @count: index counter
 * @value: value in the index
 * Return: int
 */

int print_char(char c)
{
	_putchar(c);
	return (1);
}

int print_str(char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}

int print_percent()
{
	_putchar('%');
	return (1);
}
