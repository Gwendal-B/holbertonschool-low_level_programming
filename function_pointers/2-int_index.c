#include "function_pointers.h"
#include <stddef.h>

/**
* int_index - cherche le premier element satisfaisant cmp
* @array: tableau d'entier
* @size: taille du tableau
* @cmp: fonction de comparaison
*
* Return: index du premier element trouvé ou -1
*/
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
