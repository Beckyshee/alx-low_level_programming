#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - adding two positive integers
 * @argc: arguments
 * @argv: array of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int x, z, sum = 0;

	for (x = 1; x < argc; x++)
	{
		for (z = 0; argv[x][z] != '\0'; z++)
		{
			if (!isdigit(argv[x][z]))
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[x]);
	}
	printf("%d\n", sum);

	return (0);
}
