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

	pri = va_arg(list, char*);
	if (pri == NULL)
		pri = "(null)";
	for (i = 0; pri[i] != '\0'; i++)
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
