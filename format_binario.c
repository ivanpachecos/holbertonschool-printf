#include "main.h"

int _print_a_binary(va_list args)
{
    unsigned int value_integer;
	int  i, j;
	int arr[100];

	value_integer = va_arg(args, int);
	i = 0;
	if (value_integer == 0)
	{
		_putchar('0');
		return (1);
	}
	while (value_integer > 0)
	{
		arr[i] = value_integer % 2;
		value_integer = value_integer / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(arr[j] + '0');
	return (i);
}
