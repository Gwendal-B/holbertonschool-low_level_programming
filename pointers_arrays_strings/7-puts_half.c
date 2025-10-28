#include "main.h"

/**
 *puts_half - affiche la seconde moitie d'une chaine
 *@str: pointe vers la chaine
 *
 *Return: R
 */
void puts_half(char *str)
{
	int len = 0;
	char *p = str;

	while (*p)
	{
		len++;
		p++;
	}
	if (len % 2 == 0)
		p = str + (len / 2);
	else
	p = str + ((len - 1) / 2 + 1);
	while (*p)
	{
		_putchar(*p);
		p++;
	}
	_putchar('\n');
}
