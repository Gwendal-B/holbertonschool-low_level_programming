#include "main.h"
#include <stdlib.h>

/**
 * array_range - crée un tableau d'entiers de min à max
 * @min: valeur minimale
 * @max: valeur maximale
 *
 * Return: pointeur vers le tableau, ou NULL si min > max ou échec
 */
int *array_range(int min, int max)
{
	int *array;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	array = malloc(size * sizeof(int));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = min + i;

	return (array);
}
