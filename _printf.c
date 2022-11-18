#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * printing - function to print
 * @format: String passed
 * @t: list of function calls
 * @list: arguements passed
 */

int passing(const char *format, op_t t[], va_list list)
{
	int i, j, returned_count, count;

	count = 0, i = 0, j = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			while(t[j].op != NULL)
			{
				if (format[i + 1] == t[j].op[0])
				{
					returned_count = t[j].f(list);
					if (returned_count == -1)
						return (-1);
					count += returned_count;
					break;
				}
				j++;
			}
			if (t[j].op == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] == '\0')
					return (-1);
				else
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					count += 2;
				}
			}
			i++;
		}
		i++;
	}
	return (count);
}

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
	printing(format, t, list);
	va_end(list);
	return (count);
}
