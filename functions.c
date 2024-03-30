#include "main.h"

/**
  *
  *
  *
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
