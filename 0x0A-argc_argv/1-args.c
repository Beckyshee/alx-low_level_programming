#include <stdio.h>

/**
 * main - Entry point
 * @argc: arguments
 * @argv: array of arguments
 * Return: 0 always
 */

int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
