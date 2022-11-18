#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * printing - function to print
 *
 * @format: String passed
 * @t: list of function calls
 * @list: arguements passed
 * Return: number of characters printed
 */
int printing(const char *format, op_t t[], va_list list)
{
	int i, j, _count, count;

	count = 0, i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = 0;
			while (t[j].op != NULL)
			{
				if (format[i + 1] == t[j].op[0])
				{
					_count = t[j].f(list);
					if (_count == -1)
						return (-1);
					count += _count;
					break;
				}
				j++;
			}
			if (t[j].op == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					count += 2;
				}
				else
					return (-1);
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	return (count);
}