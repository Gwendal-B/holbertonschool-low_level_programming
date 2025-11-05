#include <stdio.h>

/**
 * main - affiche le nom du programme
 * @argc: nombre d'arguments
 * @argv: tableau contenant les arguments
 *
 * Return: 0 toujours
 */
int main(int argc, char *argv[])
{
	if (argc > 0)
		printf("%s\n", argv[0]);
	return (0);
}

