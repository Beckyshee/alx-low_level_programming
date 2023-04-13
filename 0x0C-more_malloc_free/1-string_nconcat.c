#include <stdlib.h>
#include "main.h"
/**
 * string_nconcat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 * @n: bytes
 * Return: pointer to alloc mem
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int lengt1 = 0, lengt2 = 0, i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[lengt1] != '\0')
	{
		lengt1++;
	}

	while (s2[lengt2] != '\0')
	{
		lengt2++;
	}

	if (n > lengt2)
	n = lengt2;
	ptr = malloc((lengt1 + n + 1) * sizeof(char));

	if (ptr == NULL)
		return (0);

	for (i = 0; i < lengt1; i++)
	{
		ptr[i] = s1[i];
	}

	for (; i < (lengt1 + n); i++)
	{
		ptr[i] = s2[i - lengt1];
	}
	ptr[i] = '\0';

	return (ptr);
}
