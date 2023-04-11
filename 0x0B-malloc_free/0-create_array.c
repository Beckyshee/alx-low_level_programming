#include <stdlib.h>
#include "main.h"
/**
 * create_array - creates an array of chars dynamically
 * @size: size of the array
 * @c: string
 * Return: 0
 */

char *create_array(unsigned int size, char c)
{
	char *jj;
	unsigned int i;

	if (size == 0)
		return (NULL);

	jj = malloc(sizeof(c) * size);

	if (jj == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		jj[i] = c;

	return (jj);
}
