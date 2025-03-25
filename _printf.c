#include "main.h"

/**
 * handle_specifier - Handles format specifier
 * @format: format string
 * @args: argument list
 * @i: current index
 * Return: number of characters printed
 */
int handle_specifier(const char *format, va_list args, int *i)
{
	int count = 0;

	switch (format[*i])
	{
		case 'c':
			count += print_char(args);
			break;
		case 's':
			count += print_string(args);
			break;
		case '%':
			count += _putchar('%');
			break;
		default:
			count += _putchar('%');
			count += _putchar(format[*i]);
			break;
	}
	return (count);
}

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				va_end(args);
				return (-1);
			}
			count += handle_specifier(format, args, &i);
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (count);
}
