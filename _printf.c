<<<<<<< HEAD
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string contains the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifier
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list arg;
	flags_t flags = {0, 0, 0};

	int count = 0;

	va_start(arg, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			count += (pfunc)
				? pfunc(arg, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arg);
	return (count);
=======
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
>>>>>>> f0f19f1eff234060f897a2877267cc3027961721
}
