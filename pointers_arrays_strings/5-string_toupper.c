#include "main.h"

/**
 *string_toupper - convertit les minuscules en majuscules
 *@s: chaine a modifier
 *
 *Return: chaine modifier
 */
char *string_toupper(char *s)
{
	char *p = s;

	while (*p)
	{
		if (*p >= 'a' && *p <= 'z')
			*p -= 32;
		p++;
	}
	return (s);
}
