#include "main.h"

/**
 *_strcat - colle src a la fin de dest
 *@dest: chaine destination
 *@src: chaine source
 *
 *Return: pointe vers dest
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (dest);
}
