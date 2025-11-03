#include "main.h"

/**
 *_memcpy - copie une zone memoire vers une autre
 *@dest: destination
 *@src: source
 *@n: nombre d'octet a remplir
 *
 *Return: pointeur vers dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
