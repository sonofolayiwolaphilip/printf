#ifndef _PRINTF_H
#define _PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
void integers_to_string(int numb, char *string);
/*int _printf_contd(int n, va_list my_args);*/
void _printf_contd(int num)

#endif
