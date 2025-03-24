#include "main.h"

/**
 * print_char - Prints a character
 * @args: va_list args
 * Return: 1
 */
int print_char(va_list args)
{
char c = va_arg(args, int);
return (_putchar(c));
}

/**
 * print_string - Prints a string
 * @args: va_list args
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	int i = 0;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
