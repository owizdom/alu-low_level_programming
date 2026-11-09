#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the standard output
 * @filename: path of the file to read
 * @letters: maximum number of letters to read and print
 *
 * Return: number of letters read and printed, or 0 when filename is NULL,
 * the file cannot be opened or read, or write fails or writes too few bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char buf[1024];
	size_t total = 0, want;
	ssize_t nread;
	int fd;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (total < letters)
	{
		want = letters - total;
		if (want > sizeof(buf))
			want = sizeof(buf);
		nread = read(fd, buf, want);
		if (nread == 0)
			break;
		if (nread == -1 || write(STDOUT_FILENO, buf, nread) != nread)
		{
			close(fd);
			return (0);
		}
		total += nread;
	}
	close(fd);
	return (total);
}
