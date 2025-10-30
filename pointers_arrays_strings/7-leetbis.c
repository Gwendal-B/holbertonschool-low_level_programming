#include "main.h"

/**
 * leet - encode la chaîn a modifier en 1337
 * @s: chaîn a  encoder
 *
 * Return: pointeur vers la chaîne modife
 */
char *leet(char *s)
{
	int i, j;
	char lettres[] = "aAeEoOtTlL";
	char nombres[] = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; lettres[j] != '\0'; j++)
		{
			if (s[i] == lettres[j])
			{
				s[i] = nombres[j];
				break;
			}
		}
	}
	return (s);
}
