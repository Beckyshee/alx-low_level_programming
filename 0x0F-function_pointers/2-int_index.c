#include "function_pointers.h"
/**
 * int_index - searches for an int
 * @array: array input
 * @size: size of the array.
 * @cmp: pointer to the function to be used to compare to values
 *
 * Return: index cmp ! 0. If no elem return -1 If size <= 0 return -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int j;

	if (array && cmp)
	{
		if (size <= 0)
			return (-1);

		for (j = 0; j < size; j++)
			if (cmp(array[j]))
				return (j);
	}

	return (-1);
}
