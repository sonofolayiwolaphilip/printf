#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "_print.h"

int _printf(const char *format, ...)
{
	int no_of_chars = 0, i, num;
	char cha;
	char *strings;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case ('c'):
					{
						cha = va_arg(args, int);
						_putchar(cha);
						no_of_chars++;
						break;
					}
				case ('s'):
					{
						strings = va_arg(args, char*);
						for(i = 0; strings[i] != '\0'; i++)
						{
							_putchar(strings[i]);
							no_of_chars++;
						}
						break;
					}
				case ('d'):
				case ('i'):
					{
						num = va_arg(args, int);
						if (num < 0)
						{
							_putchar('-');
							no_of_chars++;
							num = -num;
						}
						no_of_chars += _printf_contd(num, args);
						break;
					}

				default:
					_putchar(*format);
					no_of_chars++;
			}
		}
		else
		{
			_putchar(*format);
			no_of_chars++;
		}
		format++;
	}
	va_end(args);
	return (no_of_chars);
}
