#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Main printf function */
int _printf(const char *format, ...);

/* Utilities */
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_binary(va_list args);
int print_pointer(va_list args);
int print_S(va_list args);
int print_reverse(va_list args);
int print_rot13(va_list args);
int print_number(unsigned long int n, int base, int is_upper);

/* Buffer handling */
int write_buffer(char *buffer, int *index, char c);
int flush_buffer(char *buffer, int index);

#endif /* MAIN_H */
