#include <stdio.h>

/**
 * main - Prints numbers between 00 to 99.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int j, k, l, m, op1, op2;

j = k = l = m = 48;
while (m < 58)
{
	l = 48;
	while (l < 58)
	{
		k = 48;
		while (k < 58)
		{
			j = 48;
			while (j < 58)
			{
				op1 = (m * 10) + l;
				op2 = (k * 10) + l;
				if (op1 < op2)
				{
					putchar(m);
					putchar(l);
					putchar(' ');
					putchar(k);
					putchar(j);
					if (m == 57 && l == 56 && k == 57 && j == 57)
						break;
					putchar(',');
					putchar(' ');
				}
				j++;
			}
			k++;
		}
		l++;
	}
	m++;
}
putchar('\n');
return (0);
}
