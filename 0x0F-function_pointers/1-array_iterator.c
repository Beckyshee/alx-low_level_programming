#include "function_pointers.h"

/**
 * array_iterator - executes pointer function as a parameter
 * @array: input
 * @size: size of the array
 * @action: pointer to function
 * Return: no return
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int j;

	if (array && size && action)
	{
		for (j = 0; j < size; j++)
		{
			(*action)(array[j]);
		}
	}
}
