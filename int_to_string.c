#include "main.h"
#include <stdbool.h>
#include <string.h>
/**
 *  * transform_rearrange - function to transformer and reverse input
 *   * @numb: the counter of the string values
 *    * @string: THe expected arguement
 *     * Return: The appropriate values
 *      */
void integers_to_string(int numb, char *string)
{
	int i = 0, my_num1, my_len;
	char my_temporal;
	if (numb < 0)
	{
		string[i++] = '-';
		numb = -numb;
	}
	while (numb > 0)
	{
		my_num1 = numb % 10;
		string[i++] = '0' + my_num1;
		numb = numb / 10;
	}
	string[i] = '\0';
	my_len = strlen(string);
	for (i = 0; i < my_len / 2; i++)
	{
		my_temporal = string[i];
		string[i] = string[my_len - i - 1];
		string[my_len - i - 1] = my_temporal;
	}
}

