#include "main.h"
#include <stdlib.h>

/**
 * _calloc - alloue un tableau et initialise a zero
 * @nmemb: nombre d'elements
 * @size: taille en octets de chaque element
 * 
 * Return: pointeur vers la memoire allouee ou NULL en cas d'echec
 */


void *_calloc(unsigned int nmemb, unsigned int size)
{
    char *ptr;
    unsigned int i;

    if (nmemb == 0 || size == 0)
        return (NULL);

    ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return (NULL);
    
    for (i = 0; i < nmemb * size; i++)
        ptr[i] = 0;

    return (ptr);
}