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
	unsigned int num = 0;

	while (*s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
		{
			num = num * 10 + (*s - '0');
		}
		else if (num > 0)
			break;
		s++;
	}
	if (sign > 0)
		return(- num);
	return(num);
}
