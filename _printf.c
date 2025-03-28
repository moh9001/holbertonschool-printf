#include "main.h"

/**
 * _printf - Custom implementation of printf
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[1024];
	int i = 0, count = 0, buf_index = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += write_buffer(buffer, &buf_index, va_arg(args, int));
					break;
				case 's':
					count += print_string(args);
					break;
				case '%':
					count += write_buffer(buffer, &buf_index, '%');
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
				case 'b':
					count += print_binary(args);
					break;
				case 'p':
					count += print_pointer(args);
					break;
				case 'S':
					count += print_S(args);
					break;
				case 'r':
					count += print_reverse(args);
					break;
				case 'R':
					count += print_rot13(args);
					break;
				default:
					count += write_buffer(buffer, &buf_index, '%');
					count += write_buffer(buffer, &buf_index, format[i]);
					break;
			}
		}
		else
		{
			count += write_buffer(buffer, &buf_index, format[i]);
		}
		i++;
	}
	count += flush_buffer(buffer, buf_index);
	va_end(args);
	return (count);
}
