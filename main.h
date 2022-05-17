#ifndef _MAIN_H_
#define _MAIN_H_
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>


void _putchar(char);
int _printf(const char *format, ...);
int print_output(const char *format, va_list val, char* buffer);


#endif
