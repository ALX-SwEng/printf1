#include <stdlib.h>
#include <stdarg.h>

int print(const char *format, va_list val, char* buffer);
int print_int(va_list);


/**
 * _printf - check if there is data to print.
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

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
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
 
int print_output(const char *format, va_list val, char* buffer)
{
	int i = 0, j=0, k = 0;
	char *tmps, tmpd[20], c;
	
	while (format[i])
	{
		if(format[i] == '%')
	  	{
	  		i++;
	 		switch (format[i]) 
	 		{
	 			case '\0':
	 				_putchar(format[i]);
	 				j++;
	 				return (j);
	 			case '%':
	 				_putchar(format[i]);
	 				j++;
	 				break;
	 			
		 	    case 'c': 
		 	        c = (char)va_arg( val, int );
		 	        _putchar (c);
		 	        j++;
		 	        break;

			    case 's':
			      	tmps = va_arg( val, char*);
					if (tmps == NULL)
						tmps = "(null)";

					while(tmps[k])
					{
						_putchar(tmps[k++]);
						j++;
					}
			        break;

		 	    case 'd':
		 	    case 'i':
		 	        j += print_i(val);
			        break;
					
				default:
					_putchar(format[i]);
					++j;
	        }
	    }
	    else
	    {
		   	_putchar(format[i]);
		   	++j;
		}
	    	i++;
	}

return (j);
}
 
 
 /**
 * print_i - prints int func
 * @arg: int to print
 * Return: number of ints printed
 */
int print_i(va_list val)
{
	int num = va_arg(val, int);
	unsigned int count = 0, revNum;
	int i = 0;
	char tab[10];

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
			tab[i] = (revNum % 10) + '0';
			revNum /= 10;
			i++;
		}
		i--;
		while (i >= 0)
		{
			_putchar(tab[i]);
			i--;
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
