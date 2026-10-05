#include "main.h"

/**
 * has_divisor - checks if a number has a divisor from i up to its square root
 * @n: the number, greater than 1
 * @i: the candidate divisor to try, greater than 1
 *
 * Return: 1 if a divisor of n is found, otherwise 0
 */
int has_divisor(int n, int i)
{
	if (i > n / i)
		return (0);
	if (n % i == 0)
		return (1);
	return (has_divisor(n, i + 1));
}

/**
 * is_prime_number - checks if an integer is a prime number
 * @n: the integer to check
 *
 * Return: 1 if n is a prime number, otherwise 0
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return (!has_divisor(n, 2));
}
