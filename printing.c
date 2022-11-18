#include "main.h"
/**
 * printing - function to print
 * @format: String passed
 * @t: list of function calls
 * @list: arguements passed
 * Return: number of characters printed
 */
int printing(const char *format, op_t t[], va_list list)
{
	int i, j, _count, count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; t[j].op != NULL; j++)
			{
				if (format[i + 1] == t[j].op[0])
				{
					_count = t[j].f(list);
					count += _count;
					break;
				}
			}
			if (t[j].op == NULL && format[i + 1] != ' ' && format[i + 1] != '\0')
			{
				_putchar(format[i]), _putchar(format[i + 1]);
				count += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	return (count);
}
