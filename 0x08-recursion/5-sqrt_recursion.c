#include "main.h"
/**
 * squ_rt - Finds the square root
 * @i: num1
 * @j: num2
 * Return: square root | -1
 */
int squ_rt(int i, int j)
{
	if (j * j > i)
		return (-1);

	else if (j * j == i)
		return (j);

	else
		return (squ_rt(i, j + 1));

	return (1);
}
/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number
 * Return: square root of n
 */
int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (squ_rt(n, 1));
}
