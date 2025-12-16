#include <stdio.h>
#include <unistd.h>

/**
 * main - compare env and environ
 * @ac: argument count
 * @av: argument vector
 * @env: environment variable
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;/*pour eviter les warning*/

	printf("Adresse de env : %p\n", (void *)env);
	printf("Adresse de environ : %p\n", (void *)environ);
	/* compare les contenus */
	if (env)
		printf("env[0] : %s\n", env[0]);
	if (environ)
		printf("environ[0] : %s\n", environ[0]);
	return (0);
}
