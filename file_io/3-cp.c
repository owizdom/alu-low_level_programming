#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 1024

/**
 * cp_fail - prints a read or write error on the standard error and exits
 * @code: exit status, 98 for a read error and 99 for a write error
 * @name: name of the file the error is about
 */
void cp_fail(int code, char *name)
{
	if (code == 98)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			name);
	else
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", name);
	exit(code);
}

/**
 * cp_close - closes a file descriptor, exits with 100 when close fails
 * @fd: file descriptor to close
 */
void cp_close(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: arguments, argv[1] is file_from and argv[2] is file_to
 *
 * Return: 0 on success; exits with 97, 98, 99 or 100 on failure
 */
int main(int argc, char *argv[])
{
	char buf[BUF_SIZE];
	ssize_t nread;
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		cp_fail(98, argv[1]);
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		cp_fail(99, argv[2]);
	while ((nread = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		if (write(fd_to, buf, nread) != nread)
			cp_fail(99, argv[2]);
	}
	if (nread == -1)
		cp_fail(98, argv[1]);
	cp_close(fd_from);
	cp_close(fd_to);
	return (0);
}
