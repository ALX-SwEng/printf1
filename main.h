#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/**
* struct modifier - A type defining a print modfier struct.
* @specifier: A character representing a type conversion specifier.
* @func: A pointer to a conversion function corresponding to specifier.
*
*/

typedef struct modifier
{
	unsigned char specifier;
	unsigned int (*func)(va_list, int);
} print_modifier;



void _putchar(char);
int _printf(const char *format, ...);
int printf_output(const char *format, va_list val);
unsigned int (*check_specifiers(const char *))(va_list, int);

unsigned int printf_c(va_list, int);
unsigned int printf_s(va_list, int);

unsigned int printf_di(va_list, int);
unsigned int printf_b(va_list val, int counter);

#endif
