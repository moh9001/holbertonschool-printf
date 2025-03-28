#include "main.h"

/**
 * print_char - Print character
 * @args: list
 * Return: 1
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Print string
 * @args: list
 * Return: number of chars
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0;

	if (!s)
		s = "(null)";

	while (s[i])
		_putchar(s[i++]);

	return (i);
}

/**
 * print_percent - Print percent sign
 * Return: 1
 */
int print_percent(void)
{
	return (_putchar('%'));
}
