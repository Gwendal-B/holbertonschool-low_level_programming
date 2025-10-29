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
	int a = 0;

	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
