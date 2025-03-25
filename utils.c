#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: character
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include "main.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: The string to measure.
 *
 * Return: Length of the string (excluding null terminator).
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * print_number - Recursively prints an unsigned int
 * @n: number to print
 * Return: number of characters printed
 */
int print_number(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_number(n / 10);

	count += _putchar((n % 10) + '0');

	return (count);
}
