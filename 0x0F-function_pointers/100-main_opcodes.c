#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcode
 * @argc: argument count of program
 * @argv: argument vector to pointers
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	char *opcde = (char *) main;
	int index, bytes;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (index = 0; index < bytes; index++)
	{
		printf("%02x", opcde[index] & 0xFF);
		if (index != bytes - 1)
			printf(" ");
	}

	printf("\n");
	return (0);
}
