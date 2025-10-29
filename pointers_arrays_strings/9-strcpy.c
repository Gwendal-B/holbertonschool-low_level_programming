#include "main.h"

/**
 *_strcpy - copie une chaine pointe par src dans dest
 *@dest: pointe vers le tableau de destination
 *@src: pointe vers la chaine
 *
 *Return: pointeur vers dest
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}
