#include "main.h"
#include <stdio.h>

/**
 * _strpbrk - cherche le premier caractère de s pesent dans accept
 * @s: chaine a parcourir
 * @accept: ensemble de caractère a chercher
 *
 * Return: pointeur vers le premier caractere correspondant, ou NULL
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				return (&s[i]);
		}
	}

	return (NULL);
}
