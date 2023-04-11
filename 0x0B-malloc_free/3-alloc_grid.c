#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: takes in width of grid
 * @height: height of grid
 * Returrn: grid
 */
int **alloc_grid(int width, int height)
{
	int **gridst;
	int i, j;

	if (width < 1 || height < 1)
		return (NULL);

	gridst = malloc(height * sizeof(int *));
	if (gridst == NULL)
	{
		free(gridst);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		gridst[i] = malloc(width * sizeof(int));
		if (gridst[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(gridst[i]);
			free(gridst);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			gridst[i][j] = 0;

	return (gridst);
}
