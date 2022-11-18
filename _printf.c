#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - performs the same function as printf
 * @format: type of arguement
 * Return: count of characters printed
 */
int _printf(const char *format, ...)
{
	int count, i;
	op_t t[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},/**
		{"d", print_float},
		{"i", print_int},*/
		{NULL, NULL}
	};
	va_list list;

	i = 0;
	if (format == NULL)
		return (-1);
	va_start(list, format);
	
	va_end(list);
	return (count);
}
