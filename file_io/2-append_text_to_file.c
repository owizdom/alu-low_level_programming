#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - appends a string at the end of an existing file
 * @filename: name of the file
 * @text_content: NULL terminated string to add, or NULL to add nothing
 *
 * Description: the file is never created.
 * Return: 1 on success, -1 when filename is NULL, the file does not exist,
 * it cannot be opened for writing, or the write fails
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t len = 0;
	int fd;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
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
