#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_format - Handles format specifiers in _printf
 * @format: The format specifier character
 * @args: The list of arguments
 *
 * Return: Number of characters printed
 */
int handle_format(char format, va_list args)
{
int count = 0;

if (format == 'c') /* Print a single character */
{
char c = va_arg(args, int);
count += write(1, &c, 1);
}
else if (format == 's') /* Print a string */
{
char *s = va_arg(args, char *);
if (s)
count += write(1, s, _strlen(s));
else
count += write(1, "(null)", 6);
}
else if (format == '%') /* Print a percentage sign */
{
count += write(1, "%", 1);
}

return (count);
}

/**
 * _printf - Custom implementation of printf function
 * @format: The format string containing text and format specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

if (!format)
return (-1);

va_start(args, format);
while (*format)
{
if (*format == '%') /* Handle format specifiers */
{
format++;
if (*format == '\0') /* Handle case where format ends with '%' */
return (-1);
count += handle_format(*format, args);
}
else /* Print regular characters */
{
count += write(1, format, 1);
}
format++;
}
va_end(args);
return (count);
}
