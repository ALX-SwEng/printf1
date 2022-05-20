#include "main.h"

/**
 * printf_di - print a formatted number.
 * @val: string to print - may contain directives.
 * @counter: character counter.
 * Return: # of characters printed.
 */

unsigned int printf_b (va_list val, int counter)
{
		long int num = va_arg(val, int);
	
	counter = num;
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
