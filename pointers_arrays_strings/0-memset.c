#include "main.h"

/**
 *_memset - remplis une zone memoire avec une valeur constante
 *@s:pointeur vers la zone memoire a remplir
 *@b:valeur a copier
 *@n: nombre d'octet a remplir
 *
 *Return: pointeur vers la zone memoire s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
