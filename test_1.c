#include "main.h"

/**
 * main - Test _printf with integers
 * Return: 0
 */
int main(void)
{
	int a = 123;
	int b = -456;

	_printf("Positive number: %d\n", a);
	_printf("Negative number: %i\n", b);
	_printf("Zero: %d\n", 0);

	return (0);
}
