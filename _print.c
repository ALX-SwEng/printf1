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
								
	va_start(args, format);
	counter = print_output(format, varAargs, buffer);
								
return (counter); 
}
