#include "main.h"
#include <stdlib.h>

/**
 * _strdup - contains a copy of the string given as a parameter..
 * @str: string.
 *
 * Return: an array of chars
 */

char *_strdup(char *str)
{
	char *strdest;
	unsigned int k, j;

	if (str == NULL)
		return (NULL);

	for (k = 0; str[k] != '\0'; k++)
		;

	strdest = (char *)malloc(sizeof(char) * (k + 1));

	if (strdest == NULL)
		return (NULL);

	for (j = 0; j <= k; j++)
		strdest[j] = str[j];

	return (strdest);
}
