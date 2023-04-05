#include "main.h"

/**
 * is_prime - shows whether a number is prime or not.
 * @a: just a number.
 * @b: val to be iterated.
 * Return: 1 if a = prime number | 0 if a !  prime number.
 */
int prime(unsigned int a, unsigned int b)
{
	if (a % b == 0)
	{
		if (a == b)
			return (1);
		else
			return (0);
	}
	return (0 + prime(a, b + 1));
}
/**
 * is_prime_number - shows whether a number is a prime number.
 * @n: number.
 * Return: 1 if n = prime number | 0 if n is ! prime number.
 */
int is_prime_number(int n)
{
	if (n == 0)
		return (0);
	if (n < 0)
		return (0);
	if (n == 1)
		return (0);
	return (is_prime(n, 2));
}
