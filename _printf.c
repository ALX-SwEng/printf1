#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - print a formatted output.
 * @format: string pointer to print - may contain directives
 * Return: # of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list varAargs;
	int counter;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(varAargs, format);
	counter = printf_output(format, varAargs);
	va_end(varAargs);
return (counter);
}

/**
 * print_output - print a formatted output.
 * @format: string pointer to print - may contain directives.
 * @val: Variable number of arguments.
 * Return: # of characters printed.
 */
int printf_output(const char *format, va_list val)
{
	int i = 0, j = 0, k = 0;
	char *tmps, c;

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				_putchar(format[i++]);
				j++; }
			else if (format[i + 1] == '\0')
			{
				_putchar(format[i]);
				return (++j); }

			i++;
			switch (format[i])
			{
			case 'c':
				c = (char)va_arg(val, int);
				_putchar(c);
				j++;
				break;
			case 's':
				tmps = va_arg(val, char*);
				if (tmps == NULL)
					return (-1);
				while (tmps[k])
				{
					_putchar(tmps[k++]);
					j++; }
				break;
			case 'd':
			case 'i':
				j += printf_int(val);
				break;
			default:
				_putchar(format[i]);
				++j; } }
		else
		{
			_putchar(format[i]);
			++j; }
	++i; }
return (j);
}
