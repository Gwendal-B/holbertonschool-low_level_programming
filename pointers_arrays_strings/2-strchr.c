#include "main.h"
#include <stdio.h>

/**
 *_strchr - localise un caractere dans une chaine
 *@s: la chaine dans laquelle chercher
 *@c: le caractere a trouver
 *
 *Return: pointeur vers la premiere occurence de c, ou NULL si non trouver
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}
