#include "main.h"
/**
 * append_text_to_file - appends text at thend of a file
 * @filename: filename.
 * @text_content: added content
 * Return: 1 if the file exists & -1 if nonexistent/fails
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int myletters;
	int rwr;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (myletters = 0; text_content[myletters]; myletters++)
			;

		rwr = write(fd, text_content, myletters);

		if (rwr == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
