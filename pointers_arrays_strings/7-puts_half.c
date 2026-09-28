#include "main.h"

/**
 * puts_half - prints the second half of a string, followed by a new line
 * @str: the string to print from
 *
 * Description: for an odd length, the last (length - 1) / 2 characters
 * are printed
 */
void puts_half(char *str)
{
	int len, i;

	len = 0;
	while (str[len] != '\0')
		len++;
	for (i = (len + 1) / 2; i < len; i++)
		_putchar(str[i]);
	_putchar('\n');
}
