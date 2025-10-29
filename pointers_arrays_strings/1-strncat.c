#include "main.h"

/**
 *_strncat - colle src a la fin de dest
 *@dest: chaine destination
 *@src: chaine source
 *@n: nombre maximal de caractere a copier
 *
 *Return: pointe vers dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src && n--)
		*p++ = *src++;
	*p = '\0';
	return (dest);
}
