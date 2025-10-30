#include "main.h"

/**
 * cap_string - met en majuscule la première lettr
 * @s: chaînea  modifier
 *
 * Return: pointeur vers la chaîne modifiée
 */
char *cap_string(char *s)
{
	char *p = s;
	int separateur = 1;

	while (*p)
	{
		if (*p == ' ' || *p == '\t' || *p == '\n' ||
				*p == ',' || *p == ';' || *p == '.' ||
				*p == '!' || *p == '?' || *p == '"' ||
				*p == '(' || *p == ')' || *p == '{' || *p == '}')
		{
			separateur = 1;
		}
		else if (separateur && *p >= 'a' && *p <= 'z')
		{
			*p -= 32;
			separateur = 0;
		}
		else
		{
			separateur = 0;
		}
		p++;
	}

	return (s);
}
