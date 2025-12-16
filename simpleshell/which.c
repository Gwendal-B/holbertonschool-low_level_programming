#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * main - mimics the behavior of the 'which' command
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	char *path_env;
	char *dir;
	char *path_copy;
	char fullpath[1024];
	int i;
	struct stat st;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", av[0]);
		return (1);
	}
	path_env = getenv("PATH");
	if (!path_env)
		return (1);

	for (i = 1; i < ac; i++)
	{
		int found = 0;

		path_copy = strdup(path_env);
		if (!path_copy)
			return (1);

		dir = strtok(path_copy, ":");
		while (dir)
		{
			snprintf(fullpath, sizeof(fullpath), "%s/%s", dir, av[i]);

			if (stat(fullpath, &st) == 0)
			{
				printf("%s\n", fullpath);
				found = 1;
				break;
			}
			dir = strtok(NULL, ":");
		}

		if (!found)
			printf("%s not found\n", av[i]);

		free(path_copy);
	}
	return (0);
}
