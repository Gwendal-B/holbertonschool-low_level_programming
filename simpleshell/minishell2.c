#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - super simple shell
 *
 * Return: Always 0
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int status;
	char *argv[2];
	extern char **environ;

	while (1)
	{
		printf("#cisboring$ ");
		fflush(stdout);

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (line[0] == '\0')
			continue;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}
		if (pid == 0)
		{
			argv[0] = line;
			argv[1] = NULL;

			execve(argv[0], argv, environ);
			perror("execve");
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
	free(line);
	return (0);
}
