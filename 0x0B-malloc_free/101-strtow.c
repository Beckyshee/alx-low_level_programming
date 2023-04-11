#include "main.h"
#include <stdlib.h>

/**
 * _free_grid - frees a 2 dimensional array.
 * @grid: multidimensional array of char.
 * @lengt: length of the array.
 *
 * Return: no return
 */
void _free_grid(char **grid, unsigned int lengt)
{
	if (grid != NULL && lengt != 0)
	{
		for (; lengt > 0; lengt--)
			free(grid[lengt]);
		free(grid[lengt]);
		free(grid);
	}
}

/**
 * strtow - splits a string into words.
 * @str: string.
 *
 * Return: pointer of an array of integers
 */
char **strtow(char *str)
{
	char **ax;
	unsigned int c, lengt, i, j, k;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (c = lengt = 0; str[c] != '\0'; c++)
		if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			lengt++;
	ax = malloc((lengt + 1) * sizeof(char *));
	if (ax == NULL || lengt == 0)
	{
		free(ax);
		return (NULL);
	}
	for (i = k = 0; i < lengt; i++)
	{
		for (c = k; str[c] != '\0'; c++)
		{
			if (str[c] == ' ')
				k++;
			if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			{
				ax[i] = malloc((c - k + 2) * sizeof(char));
				if (ax[i] == NULL)
				{
					_free_grid(ax, i);
					return (NULL);
				}
				break;
			}
		}
		for (j = 0; k <= c; k++, j++)
			ax[i][j] = str[k];
		ax[i][j] = '\0';
	}
	ax[i] = NULL;
	return (ax);
}
