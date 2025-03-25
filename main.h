#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _strlen(const char *s);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int _putchar(char c);
int print_int(va_list args);
int print_number(unsigned int n);

#endif
