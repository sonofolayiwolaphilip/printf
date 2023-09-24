#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Custom implementation of the printf function.
 *
 * This function prints formatted text to the standard output (console)
 * based on the provided format string and additional arguments. It supports
 * a variety of format specifiers (e.g., %s, %d) for different data types
 * and formatting options.
 *
 * @format: A pointer to a null-terminated format string that specifies
 * how to format the output.
 * @...: Additional arguments that correspond to the format specifiers
 * in the format string. The number and types of arguments must match
 * the format specifiers in the format string.
 *
 * Return: The number of characters printed (excluding the null terminator).
 */
int _printf(const char *format, ...)
{
	int no_of_chars = 0, i = 0, num;
	char cha, buffing[30];
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
			case 'c':
				cha = va_arg(args, int);
				putchar(cha);
				no_of_chars++;
				break;
			case 's':
				strings = va_arg(args, char *);
				for (i = 0; strings[i] != '\0'; i++)
				{
					putchar(strings[i]);
					no_of_chars++;
				}
				break;
			case 'd':
			case 'i':
				num = va_arg(args, int);
				if (num < 0)
				{
					putchar('-');
					no_of_chars++;
					num = -num;
				}
				while (num > 0)
				{
					buffing[i++] = (num % 10) + '0';
					num = num / 10;
				}
				while (i > 0)
				{
					putchar(buffing[--i]);
					no_of_chars++;
				}
				break;
			default:
				putchar(*format);
				no_of_chars++;
			}
		}
		else
		{
			putchar(*format);
			no_of_chars++;
		}
		format++;
	}
		va_end(args);
		return (no_of_chars);
}
