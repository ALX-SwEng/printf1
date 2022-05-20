#include "main.h"

/**
 * printf_c - print a formatted string.
 * @val: string to print - may contain directives.
 * @counter: character counter.
 *
 * Return: # of characters printed.
 */

unsigned int printf_c(va_list val, int counter)
{
	_putchar((char)va_arg(val, int));
	counter = 1;

	return (counter);
}

/**
 * printf_s - print a formatted string.
 * @val: string to print - may contain directives.
 * @counter: character counter.
 *
 * Return: # of characters printed.
 */

unsigned int printf_s(va_list val, int counter)
{
	char *tmps = va_arg(val, char*);
	int k = 0;

	if (tmps == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	counter = 0;

	while (tmps[k])
	{
		_putchar(tmps[k++]);
		counter++;
	}

	return (counter);
}
