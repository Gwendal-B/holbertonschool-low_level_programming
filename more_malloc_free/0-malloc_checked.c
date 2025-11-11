#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Alloue de la memoire et quitte en cas d'echec.
 * @b: taille du bloc a allouer en octets.
 *
 * Return: pointeur vers le bloc memoire alloué
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
		exit(98);

	return (ptr);
}
