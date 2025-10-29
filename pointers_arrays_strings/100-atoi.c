#include "main.h"

/**
 *_atoi - convertit une chaine de caractere en entier
 *@s: pointe vers la chaine a convertir
 *
 *Return: l'entier converti
 */
int _atoi(char *s)
{
	int a = 0, sign = 1;
	unsigned int num = 0;

	while (s[a] != '\0')
	{
		if (s[a] == '-')
			sign *= -1;
		else if (s[a] >= '0' && s[a] <= '9')
		{
			num = num * 10 + (s[a] - '0');
		}
		else if (num > 0)
			break;
		a++;
	}
	if (sign < 0)
		return (-num);
	return (num);
}
