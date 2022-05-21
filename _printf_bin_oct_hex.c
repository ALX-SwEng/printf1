#include "main.h"

/**
 * printf_b - print a formatted binary.
 * @val: string to print - may contain directives.
 * @counter: character counter.
 * Return: # of characters printed.
 */

unsigned int printf_b(va_list val, int counter)
{
	long int binary = va_arg(val, unsigned int);
	unsigned int tmp;
	int i = 0, j = 0, len = 0;
	char *table;

	tmp = binary;
	while (tmp /= 2)
		++len;
	table = malloc(sizeof(char *) * len);
	counter = 0;

	if (!binary)
	{
		_putchar('0');
		counter++;
	}
	else
	{
		while (binary)
		{
			table[j++] = (binary % 2) + '0';
			binary /= 2;
			i++;
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
