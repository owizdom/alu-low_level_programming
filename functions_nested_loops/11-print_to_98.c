#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: the number to start from
 */
void print_to_98(int n)
{
	int div, digit;

	while (1)
	{
		if (n < 0)
			_putchar('-');
		div = 1;
		while (n / div > 9 || n / div < -9)
			div *= 10;
		while (div > 0)
		{
			digit = n / div % 10;
			if (digit < 0)
				digit = -digit;
			_putchar(digit + '0');
			div /= 10;
		}
		if (n == 98)
			break;
		_putchar(',');
		_putchar(' ');
		if (n < 98)
			n++;
		else
			n--;
	}
	_putchar('\n');
}
