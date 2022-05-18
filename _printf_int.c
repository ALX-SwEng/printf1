#include "main.h"

/**
 * print_i - prints int func
 * @arg: int to print
 * Return: number of ints printed
 */
int printf_int(va_list arg)
{
	int num = va_arg(arg, int);
	unsigned int count = 0, revNum, temp;
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
		temp = revNum;
		while (temp)
		{
			temp /= 10;
			i++;
		}
		while (revNum != 0)
		{
			table[j++] = (revNum % 10) + '0';
			revNum /= 10;
		}
		i--;
		while (i >= 0)
		{
			_putchar(table[i--]);
			count++;
		}
	}
	else
	{
		_putchar('0');
		count++;
	}

	return (count);
}
