#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int i;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *envp[] = {NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			return (1);
		}

		if (pid == 0)
		{
			/* Processus enfant */
			execve("/bin/ls", argv, envp);
			perror("execve");
			exit(1);
		}
		else
		{
			/* Processus parent */
			wait(NULL);
		}
	}

	return (0);
}
