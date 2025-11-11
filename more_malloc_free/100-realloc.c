#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _realloc - réalloue une zone mémoire
 * @ptr: pointeur vers la zone mémoire de base
 * @old_size: taille de la zone mémoire de base
 * @new_size: taille de la nouvelle zone mémoire
 *
 * Return: pointeur vers la nouvelle zone mémoire ou NULL en cas d'échec
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *new_ptr;
    unsigned int i;
    char *old = ptr;
    char *new;

    if (new_size == old_size)
        return (ptr);

    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return (NULL);
    }

    if (ptr == NULL)
        return (malloc(new_size));

    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return (NULL);

    old = ptr;
    new = new_ptr;
    for (i = 0; i < old_size && i < new_size; i++)
        new[i] = old[i];

    free(ptr);
    return (new_ptr);
}
