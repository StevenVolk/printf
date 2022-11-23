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
					if (_count == -1)
						return (-1);
					count += _count;
					break;
				}
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
	}
	return (count);
}

/**
 * printing_ints -  prints integers
 * @list: arguement passed
 */
int printing_ints(va_list list)
{
	int i, j, nm;
	unsigned int k;

	nm = va_arg(list, int);
	i = 0;
	j = 1;
	if (nm < 0)
	{
		i += _putchar('-');
		k *= -1 * nm;
	}
	else
		k = n;
	
	while (k / j > 9)
	{
		j *= 10;
	}

	while (j != 0)
	{
		i += _putchar('0' + k / j);
		k %= j;
		j /= 10;
	}
	return (i);
}
