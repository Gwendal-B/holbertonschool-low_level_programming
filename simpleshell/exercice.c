#include <stdio.h>

/**
 * main - prints the argument vector
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	int i = 0;

	(void)ac;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
