#include "main.h"

/**
 * read_textfile - reads a text file and prints letters
 * @filename: filename to be read
 * @letters: numbers of letters
 * Return: no of letters printed if fails then return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t myrd, mywr;
	char *buff;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buff = malloc(sizeof(char) * (letters));
	if (!buff)
		return (0);

	myrd = read(fd, buff, letters);
	mywr = write(STDOUT_FILENO, buff, myrd);

	close(fd);

	free(buff);

	return (mywr);
}
