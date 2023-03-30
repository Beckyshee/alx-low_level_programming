#include "main.h"

/**
 * print_number - prints integers.
 * @n: input integer.
 * Return: 0.
 */
void print_number(int n)
{
	unsigned int a, c, count;

	if (n < 0)
	{
		_putchar(45);
		a = n * -1;
	}
	else
	{
		a = n;
	}

	c = a;
	count = 1;

	while (c > 9)
	{
		c /= 10;
		count *= 10;
	}

	for (; count >= 1; count /= 10)
	{
		_putchar(((a / count) % 10) + 48);
	}
}

