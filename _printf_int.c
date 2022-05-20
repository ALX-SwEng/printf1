#include "main.h"

/**
 * printf_int - prints int func
 * @arg: int to print
 * Return: number of ints printed
 */
int printf_int(va_list arg)
{
	int num = va_arg(arg, int);
	unsigned int count = 0, revNum;
	int i = 0, j = 0;
	char table[41];

	if (num < 0)
	{
		_putchar('-');
		count++;
		revNum = -num;
	}
	else
		revNum = num;

	if (revNum > 0)
	{
		while (revNum != 0)
		{
			table[j++] = (revNum % 10) + '0';
			revNum /= 10;
			i++;
		}
		i--;
		while (i >= 0)
		{
			_putchar(table[i--]);
			count++;
		}}
	else
	{
		_putchar('0');
		count++;
	}
	return (count);
}

/**
 * print_b - Print a num in binay.
 * @arg: Num to be converted to binary and printed.
 * Return: Num of bits printed.
 **/

int _printf_binary(va_list arg)
{
	unsigned int binary = va_arg(arg, unsigned int);
	int count = 0, i = 0, j = 0;
	char table[41];

	if (binary == NULL)
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
			count++;
		}
	}
	return (count);
}


/**
 * print_x - print an hexadecimal func
 *@arg: int to convert
 *Return: printed numb
 */
 
int print_x(va_list arg, int flag)
{
	long int num = va_arg(arg, long int);
	long unsigned int numRev;
	int tab[20];

	int i, j, count = 0;
	char a1[] = {"abcef"};
	char a2[] = {"ABCDEF"};
	int b[] = {10, 11, 12, 13, 14, 15};

	if (n < 0)
	{
		_putchar('-');
		count++;
		numRev = -num; }
	else
		numRev = num;

	if (numRev == 0)
	{
		_putchar('0');
		count++;
		return (count); }

	for (i = 0; numRev != 0; i++)
	{
		if (numRev % 16 < 10)
			tab[i] = numRev % 16;
		else
		{
			j = 0;
			while (j < 5)
			{
				if (numRev % 16 == b[j] & flag == 0)
				{
					tab[i] = a1[j];
					break; }
				else if (numRev % 16 == b[j] & flag == 1)
				{
					tab[i] = a2[j];
					break; }
			}
		}
		numRev = numRev / 16;
	}

	i--;
	for (; i >= 0; i--)
	{
		_putchar(a[j]);
		count++;
	}
	return (count);
}

