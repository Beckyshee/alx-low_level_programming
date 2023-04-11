#include "main.h"
#include <stdlib.h>
/**
 * free_grid - make space and free space
 * @grid: array of integers
 * @height: height of grid
 * Return: 0
 */

void free_grid(int **grid, int height)
{
	int j;

	for (j = 0; j < height; j++)
	{
		free(grid[j]);
	}

	free(grid);
}
