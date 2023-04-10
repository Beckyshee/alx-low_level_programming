#include <stdlib.h>
#include <stdio.h>

/**
 * main - multiply 2 integers
 * @argc: arguments
 * @argv: array of arguments
 * Return: 0 if it works, 1 incase there is an error
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	return (0);
}
