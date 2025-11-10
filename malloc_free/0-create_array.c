#include "main.h"
#include <stdlib.h>

/**
* create_array - crée un tableau de caractère et l'initialise
* @size: taille du tableau a créé
* @c: caractère utilisé pour initialisé le tableau
*
* Return: pointeur vers le tableau ou NULL si echec
*/

char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	array = malloc(size * sizeof(char));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
