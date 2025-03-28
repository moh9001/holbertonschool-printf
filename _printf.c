#include "main.h"

/**
 * _printf - Custom implementation of printf
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				va_end(args);
				return (-1);
			}

			switch (format[i])
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
				case 'd':
				case 'i':
					count += print_int(args);
					break;
				case 'u':
					count += print_unsigned(args);
					break;
				case 'o':
					count += print_octal(args);
					break;
				case 'x':
					count += print_hex(args, 0);
					break;
				case 'X':
					count += print_hex(args, 1);
					break;
				case 'p':
					count += print_pointer(args);
					break;
				case 'S': /* Optional: only if you implemented it correctly */
					count += print_S(args);
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
			}
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
