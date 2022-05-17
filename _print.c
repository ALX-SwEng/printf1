#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>


/**
 * _printf - print a formatted output.
 *
 * @format: string pointer to print - may contain directives.
 *
 * Return: # of characters printed.
 */

int _printf(const char *format, ...)
{
	char *buffer;
	va_list varAargs;
	int counter;

	if (format == NULL)
		return (-1);

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (-1);

	va_start(varAargs, format);
	counter = print_output(format, varAargs, buffer);
	va_end(varAargs);

return (counter);
}

/**
 * print_output - print a formatted output.
 *
 * @format: string pointer to print - may contain directives.
 * @val: Variable number of arguments.
 * @buffer: memory buffer var.
 *
 * Return: # of characters printed.
 */

int print_output(const char *format, va_list val, char *buffer)
{
	int i = 0, j = 0;
	char *tmps, tmpd[20];

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				buffer[j] = (char)va_arg(val, int);
				j++;
				break;
			case 's':
				tmps = va_arg(val, char*);
				strcpy(&buffer[j], tmps);
				j += strlen(tmps);
				break;
			case 'd':
			case 'i':
				itoa(va_arg(val, int), tmpd, 10);
				strcpy(&buffer[j], tmpd);
				j += strlen(tmpd);
				break;
			default:
				buffer[j++] = format[i];
			}
		}
		else
			buffer[j++] = format[i];
		i++;
	}
	fwrite(buffer, j, 1, stdout);

return (j);
}
