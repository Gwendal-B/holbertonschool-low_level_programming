#include <stdio.h>

/**
 *main - affiche tous les arguments reçus
 *@argc: nombre d'arguments passés au programme
 *@argv: tableau contenant les arguments
 *
 *Return: 0 toujours
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}

