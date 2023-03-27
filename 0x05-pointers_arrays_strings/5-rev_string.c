#include "main.h"

/**
 * rev_string - reverses a string.
 * @s: input string.
 * Return: no return.
 */
void rev_string(char *s)
{
	int count = 0, j, k;
	char *str, name;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (j = 0; j < (count - 1); j++)
	{
		for (k = j + 1; k > 0; k--)
		{
			name = *(str + k);
			*(str + k) = *(str + (k - 1));
			*(str + (k - 1)) = name;
		}
	}
}
