#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: name of the file (for error message).
 *
 * Return: pointer to the buffer.
 */
char *create_buffer(const char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);
	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buf);
}

/**
 * close_file - Closes a file descriptor and handles errors.
 * @fd: File descriptor to close.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - Copies content from one file to another.
 * @fd_from: File descriptor of the source file.
 * @fd_to: File descriptor of the destination file.
 * @buf: Buffer to use for copying.
 * @file_from: Name of the source file (for error message).
 * @file_to: Name of the destination file (for error message).
 */

static void copy_file(int fd_from, int fd_to, char *buf, const char *file_from,
                      const char *file_to)
{
    ssize_t r, w;

    while ((r = read(fd_from, buf, 1024)) > 0)
    {
        w = write(fd_to, buf, r);
        if (w != r)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
            free(buf);
            close_file(fd_from);
            close_file(fd_to);
            exit(99);
        }
    }

    if (r == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
        free(buf);
        close_file(fd_from);
        close_file(fd_to);
        exit(98);
    }
}

/**
 * main - Entry point for the cp program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, exits with various codes on failure.
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to;
    char *buffer;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    buffer = create_buffer(argv[2]);
    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        free(buffer);
        exit(98);
    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        free(buffer);
        close_file(fd_from);
        exit(99);
    }

    copy_file(fd_from, fd_to, buffer, argv[1], argv[2]);

    free(buffer);
    close_file(fd_from);
    close_file(fd_to);

    return (0);
}