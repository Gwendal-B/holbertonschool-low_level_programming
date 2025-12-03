#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * print_error - prints an error message to STDERR
 * @msg: string to print
 */
void print_error(const char *msg)
{
	int i = 0;

	while (msg[i])
	{
		write(STDERR_FILENO, &msg[i], 1);
		i++;
	}
}

/**
 * create_buffer - Allocates 1024 bytes for buffer
 * @file: filename for error message
 *
 * Return: pointer to buffer
 */
char *create_buffer(const char *file)
{
	char *buf = malloc(sizeof(char) * BUFFER_SIZE);

	if (!buf)
	{
		print_error("Error: Can't write to ");
		print_error(file);
		print_error("\n");
		exit(99);
	}
	return (buf);
}

/**
 * close_file - closes a file descriptor, exit 100 if fail
 * @fd: file descriptor
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		print_error("Error: Can't close fd ");
		/* convert fd to string manually */
		char num[12];
		int i = 0, j, temp, len = 0;

		temp = fd;
		if (temp == 0)
		{
			write(STDERR_FILENO, "0\n", 2);
			exit(100);
		}
		if (temp < 0)
		{
			write(STDERR_FILENO, "-", 1);
			temp = -temp;
		}
		while (temp > 0)
		{
			num[len++] = (temp % 10) + '0';
			temp /= 10;
		}
		for (j = len - 1; j >= 0; j--)
			write(STDERR_FILENO, &num[j], 1);
		write(STDERR_FILENO, "\n", 1);
		exit(100);
	}
}

/**
 * main - copies content of file_from to file_to
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	char *buffer;

	if (argc != 3)
	{
		print_error("Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		print_error("Error: Can't read from file ");
		print_error(argv[1]);
		print_error("\n");
		free(buffer);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		print_error("Error: Can't write to ");
		print_error(argv[2]);
		print_error("\n");
		free(buffer);
		close_file(fd_from);
		exit(99);
	}

	while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r || w == -1)
		{
			print_error("Error: Can't write to ");
			print_error(argv[2]);
			print_error("\n");
			free(buffer);
			close_file(fd_from);
			close_file(fd_to);
			exit(99);
		}
	}

	if (r == -1)
	{
		print_error("Error: Can't read from file ");
		print_error(argv[1]);
		print_error("\n");
		free(buffer);
		close_file(fd_from);
		close_file(fd_to);
		exit(98);
	}

	free(buffer);
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
