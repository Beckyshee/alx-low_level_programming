#include <stdio.h>

/**
 * main - Prints numbers between 012 to 789.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int j, k, l;

	j = 48;
	k = 48;
	l = 48;

	while (k < 58)
	{
		j = 48;
		while (j < 58)
		{
			l = 48;
			while (l < 58)
			{
				if (k != j && k != l && j != l && k < j && j < l)
				{
					putchar(k);
					putchar(j);
					putchar(l);
					if (j == 56 && k == 55 && l == 57)
					{
						break;
					}
					putchar(',');
					putchar(' ');
				}
				l++;
			}
			j++;
		}
		k++;
	}
	putchar('\n');
	return (0);
}
