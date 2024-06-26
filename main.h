#ifndef _MAIN_H
#define _MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
  * struct specifiers - Struct specifiers
  * @specifier: The conversion specifier
  * @f: The function pointer
  */

typedef struct specifiers
{
	char *specifier;
	int (*f)(va_list args);
} fmt_spc;

int _putchar(char c);
int print_format(const char *format, va_list args);
int _print_invalid_spec(char prev_format, char format, int count);
int _printf(const char *format, ...);
int print_char(va_list args);
int _print_a_string(va_list args);
int _print_spec(char format, va_list args);
int _print_a_integer(va_list args);
void _recursion_integer(int a);
int _validate_char(char _type);

#endif
