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
	char cha, buffing[12]; /* Buffer for integers */
	char *strings;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				cha = va_arg(args, int);
				write(1, &cha, 1);
				no_of_chars++;
				break;
			case 's':
				strings = va_arg(args, char *);
				while (strings[i])
				{
					write(1, &strings[i], 1);
					no_of_chars++;
					i++;
				}
				i = 0;
				break;
			case 'd':
			case 'i':
				num = va_arg(args, int);
				if (num < 0)
				{
					write(1, "-", 1);
					no_of_chars++;
					num = -num;
				}
				if (num == 0)
				{
					write(1, "0", 1);
					no_of_chars++;
				}
				i = 0;
				while (num > 0)
				{
					buffing[i++] = (num % 10) + '0';
					num /= 10;
				}
				while (i > 0)
				{
					i--;
					write(1, &buffing[i], 1);
					no_of_chars++;
				}
				break;
			default:
				write(1, "%", 1);
				no_of_chars++;
				if (*format)
				{
					write(1, format, 1);
					no_of_chars++;
				}
			}
		}
		else
		{
			write(1, format, 1);
			no_of_chars++;
		}
		format++;
	}
	va_end(args);
	return (no_of_chars);

}