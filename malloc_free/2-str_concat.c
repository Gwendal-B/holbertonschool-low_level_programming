#include "main.h"
#include <stdlib.h>

/**
* str_concat - concatène deux chaîne de caractère
* @s1: première chaîne
* @s2: deuxieme chaîne
*
* Return: pointeur vers la nouvelle chaine ou NULL si echec
*/
char *str_concat(char *s1, char *s2)
{
	char *suite;
	unsigned int i, j, len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	suite = malloc(sizeof(char) * (len1 + len2 + 1));

	if (suite == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		suite[i] = s1[i];

	for (j = 0; j < len2; j++)
		suite[i + j] = s2[j];

	suite[i + j] = '\0';

	return (suite);
}
