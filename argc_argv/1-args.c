#include <stdio.h>

/**
 * main - affiche le nombre d'arguments passés au programme
 * @argc: nombre total d'arguments
 * @argv: tableau contenant les arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int count = argc - 1;

	(void) argv;
	printf("%d\n", count);

	return (0);
}

