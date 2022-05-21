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

/**
 * printf_o - print a formatted octal.
 * @val: string to print - may contain directives.
 * @counter: character counter.
 * Return: # of characters printed.
 */

unsigned int printf_o(va_list val, int counter)
{
	long int octal = va_arg(val, unsigned int);
	unsigned int tmp;
	int i = 0, j = 0, len = 0;
	char *table;

	tmp = octal;
	while (tmp /= 8)
		++len;
	table = malloc(sizeof(char *) * len);
	counter = 0;

	if (!octal)
	{
		_putchar('0');
		counter++;
	}
	else
	{
		while (octal)
		{
			table[j++] = (octal % 8) + '0';
			octal /= 8;
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

/**
 * printf_x - print a formatted hexadecimal.
 * @val: string to print - may contain directives.
 * @flag: to print small-case or upper-case hexa.
 * Return: # of characters printed.
 */

unsigned int printf_x(va_list val, int flag)
{
	long int hexa = va_arg(val, unsigned int);
	unsigned int tmp;
	int i = 0, j = 0, k, counter;
	char *table;
	char *small = "abcdef";
	char *capital = "ABCDEF";

	tmp = hexa;
	while (tmp /= 16)
		++counter;
	table = malloc(sizeof(char *) * counter);
	counter = 0;

	if (!hexa)
	{
		_putchar('0');
		counter++;
	}
	else
	{
		while (hexa)
		{
			k = 0;
			if (hexa % 16 < 10)
				table[j++] = (hexa % 16) + '0';
			else if (flag == 1)
			{
				while (capital[k])
					if (hexa % 16 == capital[k++])
						table[j++] = capital[k - 1];
			}
			else if (flag == 0)
			{
				while (capital[k])
					if (hexa % 16 == small[k++])
						table[j++] = small[k - 1];
			}
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

/**
 * printf_X - print a formatted hexadecimal.
 * @val: string to print - may contain directives.
 * @flag: to print small-case or upper-case hexa.
 * Return: # of characters printed.
 */

unsigned int printf_X(va_list val, int flag)
{
	return (printf_x (val, flag + 1));
}
