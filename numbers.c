#include "main.h"

/**
 * print_int - Print signed integer
 * @args: list
 * Return: printed characters
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	count += print_number(num, 10, 0);
	return (count);
}

/**
 * print_unsigned - Print unsigned int
 * @args: list
 * Return: printed characters
 */
int print_unsigned(va_list args)
{
	return (print_number(va_arg(args, unsigned int), 10, 0));
}

/**
 * print_octal - Print octal
 * @args: list
 * Return: printed characters
 */
int print_octal(va_list args)
{
	return (print_number(va_arg(args, unsigned int), 8, 0));
}

/**
 * print_hex - Print hexadecimal (lowercase or uppercase)
 * @args: list
 * @uppercase: 1 for uppercase, 0 for lowercase
 * Return: printed characters
 */
int print_hex(va_list args, int uppercase)
{
unsigned int num = va_arg(args, unsigned int);

return (print_number(num, 16, uppercase));
}

/**
 * print_binary - Print binary
 * @args: list
 * Return: printed characters
 */
int print_binary(va_list args)
{
	return (print_number(va_arg(args, unsigned int), 2, 0));
}

/**
 * print_number - Recursive base printer
 * @n: number to print
 * @base: base to use (e.g., 2, 8, 10, 16)
 * @is_upper: 1 for uppercase hex, 0 otherwise
 * Return: printed characters
 */
int print_number(unsigned long int n, int base, int is_upper)
{
	char *digits = is_upper ? "0123456789ABCDEF" : "0123456789abcdef";
	int count = 0;


	if (n / base)
		count += print_number(n / base, base, is_upper);

	count += _putchar(digits[n % base]);
	return (count);
}

/**
 * print_hex_lower - Prints a number in hexadecimal (lowercase).
 * @args: A list of arguments passed to the function.
 *
 * Return: The number of characters printed.
 */
int print_hex_lower(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);  /* Get the number from the argument list */
    return print_number(num, 16, 0);  /* 0 means use lowercase letters for hex digits */
}

/**
 * print_hex_upper - Prints a number in hexadecimal (uppercase).
 * @args: A list of arguments passed to the function.
 *
 * Return: The number of characters printed.
 */
int print_hex_upper(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);  /* Get the number from the argument list */
    return print_number(num, 16, 1);  /* 1 means use uppercase letters for hex digits */
}
