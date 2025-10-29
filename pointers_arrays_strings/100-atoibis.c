#include "main.h"

/**
 *_atoi - convertit une chaine de caractere en entier
 *@s: pointe vers la chaine a convertir
 *
 *Return: l'entier converti
 */
int _atoi(char *s)
{
	int sign = 1;
	int num = 0;
	int start = 0;

	while (*s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
		{
			start = 1;
			num = num * 10 + (*s - '0');
		}
		else if (start)
			break;
		s++;
	}
	return(num * sign);
}
