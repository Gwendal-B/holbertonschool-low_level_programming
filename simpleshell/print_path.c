#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

/**
 * _getenv - récupère la valeur d'une variable d'environnement
 * @name: nom de la variable (ex: "PATH")
 *
 * Return: pointeur vers la valeur, ou NULL si non trouvé
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len;

	if (!name)
		return (NULL);

	len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
		i++;
	}

	return (NULL);
}

/**
 * print_path_dirs - affiche chaque répertoire de PATH sur une ligne
 */
void print_path_dirs(void)
{
	char *path = _getenv("PATH");
	char *path_copy;
	char *dir;

	if (!path)
	{
		printf("PATH not found\n");
		return;
	}

	/* On fait une copie car strtok modifie la chaîne */
	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("strdup");
		return;
	}

	dir = strtok(path_copy, ":");
	while (dir)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
}

/**
 * main - test de la fonction print_path_dirs
 *
 * Return: Always 0.
 */
int main(void)
{
	print_path_dirs();
	return (0);
}
