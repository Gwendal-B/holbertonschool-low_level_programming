#include "main.h"

/**
 * print_alphabet_x10 - affiche l'alphabet en minuscules 10 fois suivi
 *d'un saut de ligne
 */
void print_alphabet_x10(void)
{
	char lettre;
	int i;

	for (i = 0; i < 10; i++)
	{
		for (lettre = 'a'; lettre <= 'z'; lettre++)
		{
			_putchar(lettre);
		}
		_putchar('\n');
	}
}
