#include "main.h"

/**
 * print_pointer - Print memory address
 */
int print_pointer(va_list args)
{
	unsigned long ptr = (unsigned long)va_arg(args, void *);
	int count = 0;

	if (!ptr)
		return (_putchar('(') + _putchar('n') + _putchar('i') + _putchar('l') + _putchar(')'));

	count += _putchar('0');
	count += _putchar('x');
	count += print_number(ptr, 16, 0);
	return (count);
}

/**
 * print_S - Print string with non-printables
 */
int print_S(va_list args)
{
	char *str = va_arg(args, char *);
	char *digits = "0123456789ABCDEF";
	int i, count = 0;
	char hex[5];

	if (!str)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			hex[0] = digits[(str[i] >> 4) & 0xF];
			hex[1] = digits[str[i] & 0xF];
			count += _putchar(hex[0]);
			count += _putchar(hex[1]);
		}
		else
			count += _putchar(str[i]);
	}
	return (count);
}

/**
 * print_reverse - Print reversed string
 */
int print_reverse(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0, i;

	if (!s)
		s = "(null)";

	while (s[len])
		len++;

	for (i = len - 1; i >= 0; i--)
		_putchar(s[i]);

	return (len);
}

/**
 * print_rot13 - ROT13 encoded string
 */
int print_rot13(va_list args)
{
	char *s = va_arg(args, char *);
	int i, count = 0;
	char c;

	if (!s)
		s = "(null)";

	for (i = 0; s[i]; i++)
	{
		c = s[i];
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
				c += 13;
			else
				c -= 13;
		}
		count += _putchar(c);
	}
	return (count);
}
