#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * op_add - addition
 * @a: 1st number
 * @b: 2nd number
 * Return: sum
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - subtraction
 * @a: 1st number
 * @b: 2nd number
 * Return: diff
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - is a function that performs multiplication
 * @a: 1st number
 * @b: 2nd number
 * Return: multiplication
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - division
 * @a: first number
 * @b: second number
 * Return: division
 */
int op_div(int a, int b)
{
	if (b)
	{
		return (a / b);
	}
	printf("Error\n");
	exit(100);
}
/**
 * op_mod - modulus
 * @a: first number
 * @b: second number
 * Return: remainder
 */
int op_mod(int a, int b)
{
	if (b)
	{
		return (a % b);
	}
	printf("Error\n");
	exit(100);
}
