#include "main.h"
#include <stdlib.h>

/**
 * argstostr - prints args of a program
 * @ac: argument count
 * @av: argument vector
 * Return: array
 */

char *argstostr(int ac, char **av)
{
	char *strout;
	int c = 0, i = 0, j = 0, k = 0;

	if (ac == 0 || av == NULL)
		return (NULL);
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			c++;
			j++;
		}
		i++;
	}
	c = c + ac + 1;
	strout = malloc(sizeof(char) * c);
	if (strout == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			strout[k] = av[i][j];
			k++;
		}
		strout[k] = '\n';
		k++;
	}
	return (strout);
}
