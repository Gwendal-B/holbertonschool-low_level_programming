#include "main.h"

/**
 * _strspn - obtient la longueur du prefixe d'une sous-chaine
 * @s: chaine principale
 * @accept: caracteres acceptes
 *
 * Return: nombre d’octets initiaux de s qui appartiennent a accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, count = 0;
	int match;

	for (i = 0; s[i] != '\0'; i++)
	{
		match = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				match = 1;
				break;
			}
		}
		if (match == 0)
			break;
		count++;
	}
	return (count);
}
