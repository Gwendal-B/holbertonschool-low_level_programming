#include "main.h"
#include <stdio.h>

/**
 *print_array - affiche n element du tableau
 *@a: pointe vers le premier element du tableau
 *@n: nombre d'element a afficher
 *
 *Return: R
 */
void print_array(int *a, int n)
{
	int b;

	for (b = 0; b < n; b++)
	{
		printf("%d", a[b]);

		if (b != n - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}
