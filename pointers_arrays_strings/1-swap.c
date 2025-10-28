#include "main.h"

/**
 *swap_int - ehange les valeurs de deux entiers
 *@a: valeur du premier pointeur
 *@b: valeur du second pointeur
 *
 *Return: R
 */
void swap_int(int *a, int *b)
{
	int temporaire;

	temporaire = *a;
	*a = *b;
	*b = temporaire;
}
