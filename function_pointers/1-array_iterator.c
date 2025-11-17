#include "function_pointers.h"
#include <stddef.h>

/**
* array_iterator - execute une fonction sur chaque element du tableau
* @array: tableau d'entier
* @size: nombre d'element a parcourir
* @action: fonction a appliquer
*
* Return: Rien
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
