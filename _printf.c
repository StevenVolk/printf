#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints the char variable
 * @list: what to be printed
 * Return: Always 1 for a character
 */
int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * print_string - prints a string
 * @list: what to be printed
 * Return: number of characters printed
 */
int print_string(va_list list)
{
	int i;
	char *pri;

	pri = va_arg(list, char *);
	if (pri == NULL)
		pri = "null";
	for (i = 0; i != '\0'; i++)
		_putchar(pri[i]);
	return (i);
}

/**
 * print_percent - prints a percentage symbol
 * @list: what to be printed
 * Return: Always 1 for a percentage symbol
 */
int print_percent(__attribute__((unused)) va_list list)
{
	_putchar('%');
	return (1);
}

/**
 * _printf - performs the same function as printf
 * @format: type of arguement
 * Return: count of characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	op_t t[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_float},
		{"i", print_int},
		{NULL, NULL}
	};
	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	count = parser(format, t, list);
	va_end(list);
	return (count);
}
