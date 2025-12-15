#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **strtow(char *str)
{
	char **words = NULL;
	char *token;
	int i = 0;

	words = malloc(sizeof(char *) * 64);
	if (!words)
		return (NULL);

	token = strtok(str, " \t\n");
	while (token)
	{
		words[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	words[i] = NULL;

	return (words);
}

int main(void)
{
	char input[] = "Bonjour, Holla, Halo, Hello";
	char **av = strtow(input);
	int i = 0;

	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
