#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers.
 * @min: minimum
 * @max: maximum
 * Return: pointer to an array.
 */

int *array_range(int min, int max)
{
	int *a, i;

	if (min > max)
		return (NULL);

	a = malloc(sizeof(*a) * ((max - min) + 1));

	if (a == NULL)
		return (NULL);

	for (i = 0; min <= max; i++, min++)
		a[i] = min;

	return (a);
}
