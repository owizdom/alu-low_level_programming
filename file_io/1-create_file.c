#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * create_file - creates a file with permissions rw------- and writes a string
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write, or NULL for an empty file
 *
 * Description: an existing file is truncated and keeps its permissions.
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	ssize_t len = 0;
	int fd;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
		if (write(fd, text_content, len) != len)
		{
			close(fd);
			return (-1);
		}
	}
	if (close(fd) == -1)
		return (-1);
	return (1);
}
