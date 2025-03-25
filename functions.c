#include "main.h"

/**
 * print_char - Prints a character
 * @args: Argument list
 * Return: Number of characters printed (1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	return (_putchar(c));
}

/**
 * print_string - Prints a string
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
