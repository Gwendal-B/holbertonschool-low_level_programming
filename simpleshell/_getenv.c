#include <stdio.h>
#include <string.h>

extern char **environ; /* variable globale contenant l'environnement */

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
		/* Vérifie si la variable commence par "name=" */
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			/* Retourne juste la valeur après '=' */
			return (&environ[i][len + 1]);
		}
		i++;
	}

	return (NULL); /* variable non trouvée */
}

/**
 * main - test de la fonction _getenv
 *
 * Return: Always 0.
 */
int main(void)
{
	char *value;

	value = _getenv("PATH");
	if (value)
		printf("PATH=%s\n", value);
	else
		printf("PATH not found\n");

	value = _getenv("HOME");
	if (value)
		printf("HOME=%s\n", value);
	else
		printf("HOME not found\n");

	return (0);
}
