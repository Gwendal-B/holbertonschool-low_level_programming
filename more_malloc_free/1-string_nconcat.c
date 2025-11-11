#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatène s1 et s2 (n premiers caractères de s2)
 * @s1: première chaîne
 * @s2: deuxième chaîne
 * @n: nombre de caractères à copier depuis s2
 *
 * Return: pointeur vers la nouvelle chaîne ou NULL en cas d'échec
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2, i, j;
	char *nouvelle_chaine;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = strlen(s1);
	len2 = strlen(s2);
	if (n > len2)
		n = len2;

	nouvelle_chaine = malloc(len1 + n + 1);
	if (nouvelle_chaine == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		nouvelle_chaine[i] = s1[i];
	for (j = 0; j < n; j++)
		nouvelle_chaine[i + j] = s2[j];

	nouvelle_chaine[i + j] = '\0';

	return (nouvelle_chaine);
}
