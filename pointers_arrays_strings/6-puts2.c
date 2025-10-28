#include "main.h"

/**
 *puts2 - affiche un caracter sur 2 d'un chaine
 *@str: pointeur vers la chaine de caractere
 *
 *Return: R
 */
void puts2(char *str)
{
	int a = 0;

	while (*str)
	{
		if (a == 0)
			_putchar(*str);
		a = 1 - a;
		str++;
	}
	_putchar('\n');
}
