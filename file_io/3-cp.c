#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

int cp_file_to_file(const char *source, const char *destination);
void close_fd(int fd);

/**
 * main - check the code
 * @ac: argc
 * @av: argv
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	cp_file_to_file(av[1], av[2]);
	return (0);
}

/**
 * cp_file_to_file - Copies the content of one file into another.
 * @source: Name of the source file.
 * @destination: Name of the destination file.
 *
 * Return: 0 on success, or exits on failure.
 */
int cp_file_to_file(const char *source, const char *destination)
{
	int src, dst;
	ssize_t nread, nwritten;
	char buffer[1024];
	char *out_ptr;

	src = open(source, O_RDONLY);
	if (src == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		exit(98);
	}

	dst = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (dst == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", destination);
		close_fd(src);
		exit(99);
	}

	while ((nread = read(src, buffer, sizeof(buffer))) > 0)
	{
		out_ptr = buffer;
		do {
			nwritten = write(dst, out_ptr, nread);
			if (nwritten == -1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", destination);
				close_fd(src);
				close_fd(dst);
				exit(99);
			}
			nread -= nwritten;
			out_ptr += nwritten;
		} while (nread > 0);
	}
	if (nread == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		close_fd(src);
		close_fd(dst);
		exit(98);
	}

	close_fd(dst);
	close_fd(src);
	return (0);
}

/**
 * close_fd - Closes a file descriptor and handles errors.
 * @fd: File descriptor to close.
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
