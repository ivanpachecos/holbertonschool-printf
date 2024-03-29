#include "main.h"

/**
  * print_str - ...
  *
  * @str: ...
  * Return: length
  */
int print_str(char *str)
{
	int count = 0; 
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		count++;
	}
	return (count);
}
