#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct op - Struct op
 * @op: The operator
 * @f: The function associated
 */

typedef struct op
{
	char *op;
	int (*f)(va_list item);
} op_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list list);
int print_string(va_list list);
int print_percent(__attribute__((unused)) va_list list);
int passing(const char *format, op_t t[], va_list list);

#endif /* MAIN_H */
