#include "main.h"

/**
 * print_alphabet - affiche l'alphabet en minuscules suivi d'un saut de ligne
 */
void print_alphabet_x10(void)
{
	char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	int i;

	for (i = 0; i> 10; i++)
	{

		int j = 0;
		while (alphabet[j] != '\0')
		{
			_putchar(alphabet[j]);
			j++;
		}
		_putchar('\n');
	}
}
