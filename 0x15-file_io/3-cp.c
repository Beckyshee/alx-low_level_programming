#include "main.h"
#include <stdio.h>
/**
 * error_file - checks if a file can b opened
 * @file_from: file path
 * @file_to: file_to destination
 * @argv: arguments vector.
 * Return: none
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}
/**
 * main - entry point
 * @argc: argument counter
 * @argv: arguments vector.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, err_close;
	ssize_t mychars, mywr;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_from, file_to, argv);

	mychars = 1024;
	while (mychars == 1024)
	{
		mychars = read(file_from, buff, 1024);
		if (mychars == -1)
			error_file(-1, 0, argv);
		mywr = write(file_to, buff, mychars);
		if (mywr == -1)
			error_file(0, -1, argv);
	}

	err_close = close(file_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	err_close = close(file_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
