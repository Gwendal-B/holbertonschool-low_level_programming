#include <stdio.h>

/**
 *main - affiche le nombre d'arguments passés au programme
 *@argc: nombre total d'arguments
 *@argv: tableau contenant les arguments
 *
 *Return: 0 toujours
 */
int main(int argc, char *argv[])
{
	(void) argv;
	
	printf("%d\n", argc - 1);
	return (0);
}
