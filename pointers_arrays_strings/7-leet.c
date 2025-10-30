#include "main.h"

/**
 * leet - encode la chaîn a modifier en 1337
 * @s: chaîn a  encoder
 *
 * Return: pointeur vers la chaîne modife
 */
char *leet(char *s)
{
	char *p = s;
	char lettres[] = "aAeEoOtTlL";
	char nombres[] = "4433007711";
	int i;

	while (*p)
	{
		for (i = 0; lettres[i] != '\0'; i++)
		{
			if (*p == lettres[i])
			{
				*p = nombres[i];
				break;
			}
		}
		p++;
	}
	return (s);
}
