#include "main.h"

**
 * printf_b - print a formatted binary.
 * @val: string to print - may contain directives.
 * @counter: character counter.
 * Return: # of characters printed.
 */

unsigned int printf_b(va_list val, int counter)
{
	unsigned int binary = va_arg(arg, unsigned int);
	unsigned int tmp;
	int count = 0, i = 0, j = 0, len = 0;
	char *table;

	tmp = num;
	while (tmp /= 10)
		++len;
	table = malloc(sizeof(long int) * len);
	
	if (!binary)
	{
		_putchar('0');
		count++;
	}
	else
	{
	
		while (binary)
		{
			table[j++] = (binary % 2) + '0';
			binary /= 2;
		}

		i--;
		while (i >= 0)
		{
			_putchar(table[i]);
			i--;
			counter++;
		}
	}
	free(table);

	return (counter);
}


unsigned int printf_o (va_list val, int counter)
{
		long int num = va_arg(val, int);
	
	counter = num;
	return (counter);
}

unsigned int printf_x (va_list val, int flag)
{
	long int num = va_arg(val, int);
	int counter = 0;

	if (flag == 1)
		_putchar('H');
	else
		_putchar('O');
	counter = num;
	
	return (counter);
}

unsigned int printf_X (va_list val, int flag)
{
	int counter = 0;
	long int num = va_arg(val, int);
	if (flag == 1)
		_putchar('H');
	else
		_putchar('O');
	
	counter = num;
	return (counter);
}
