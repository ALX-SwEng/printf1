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
 * printf_output - print a formatted output.
 * @format: string pointer to print - may contain directives.
 * @val: Variable number of arguments.
 * Return: # of characters printed.
 */
int printf_output(const char *format, va_list val)
{
	int i = 0, counter = 0;
	unsigned int (*f)(va_list, int);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				_putchar(format[i]);
				++counter;
			}
			else
			{
				i++;
				f = check_specifiers(format + i);
				if (f == NULL)
				{
					if (format[i] != '%')
						_putchar(format[i - 1]);
					_putchar(format[i]);
					++counter;
				}
				else
					counter += f(val, 0);
			}
		}
		else
		{
			_putchar(format[i]);
			++counter;
		}
		++i;
	}
return (counter);
}

/**
 * check_specifiers - Matches a specifier
 *					with a corresponding print function.
 * @specifier: A pointer to a potential specifier.
 *
 * Return: a pointer to the function if specifier is matched,
 *         Otherwise - NULL.
 */

unsigned int (*check_specifiers(const char *specifier))(va_list, int)
{
	int j;
	print_modifier modifier[] = {
								{'c', printf_c},
								{'s', printf_s},
								{'d', printf_di},
								{'i', printf_di},
								{0, NULL}
							};
	for (j = 0; modifier[j].func; j++)
	{
		if (modifier[j].specifier == *specifier)
			return (modifier[j].func);
	}

	return (NULL);
}
