#ifndef _MAIN_H_
#define _MAIN_H_

void _putchar(char);
int _printf(const char *format, ...);
int print_output(const char *format, va_list val, char* buffer);
int print(const char *format, va_list val, char* buffer);
int printf_int(va_list arg);

#endif
