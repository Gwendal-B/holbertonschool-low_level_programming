#include "main.h"

/**
 *puts_half - affiche la seconde moitie d'une chaine
 *@str: pointe vers la chaine
 *
 *Return: R
 */
void puts_half(char *str)
{
	int len = 0, i;

	while (str[len] != '\0')
		len++;

	for (i = (len + 1) / 2; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}
