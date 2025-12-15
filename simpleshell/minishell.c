#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("#cisboring$ ");
		read = getline(&line, &len, stdin);

		if (read == -1) /* EOF (Ctrl+D) */
		{
			printf("\n");
			break;
		}

		/* Supprimer le '\n' à la fin de la ligne */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (line[0] == '\0') /* Entrée vide */
			continue;

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			continue;
		}

		if (pid == 0) /* Enfant */
		{
			char *argv[] = {line, NULL};
			char *envp[] = {NULL};

			execve(line, argv, envp);
			perror("execve"); /* Si execve échoue */
			exit(1);
		}
		else /* Parent */
		{
			wait(NULL); /* Attendre l’enfant */
		}
	}

	free(line);
	return 0;
}
