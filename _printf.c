#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Prints formatted output to standard output.
 * @format: A string containing the text and format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c') /* Handle character format */
			{
				char c = va_arg(args, int);

				count += write(1, &c, 1);
			}
			else if (*format == 's') /* Handle string format */
			{
				char *s = va_arg(args, char *);

				if (s)
					count += write(1, s, _strlen(s));
				else
					count += write(1, "(null)", 6);
			}
			else if (*format == '%') /* Handle '%%' escape */
			{
				count += write(1, "%", 1);
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
