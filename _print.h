#ifndef _PRINTF_H
#define _PRINTF_H
#include <unistd.h>
#include <stdarg.h>
int _putchar(char c);
int _printf(const char *format, ...);
void integers_to_string(int numb, char *string);
#endif
