#include "main.h"

/**
 * find_sqrt - searches the natural square root of a number, from i upwards
 * @n: the number, greater than 0
 * @i: the candidate root to try, greater than 0
 *
 * Return: the natural square root of n, or -1 if there is none
 */
int find_sqrt(int n, int i)
{
	if (i > n / i)
		return (-1);
	if (n / i == i && n % i == 0)
		return (i);
	return (find_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number
 *
 * Return: the natural square root of n, or -1 if n does not have one
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	return (find_sqrt(n, 1));
}
