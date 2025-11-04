#include "main.h"

/**
 *_sqrt_aide - aide a calculer la racine carree
 *@n: nombre dont on veut calculer la racine
 *@i: candidat pour la racine
 *
 *Return:
 *   - racine carree de n si elle existe
 *   - -1 si n n'a pas de racine exacte
 */
int _sqrt_aide(int n, int i)
{
	if (i * i == n) /* check reussi*/
		return (i);
	if (i * i > n) /* mauvais au check*/
		return (-1);
	return (_sqrt_aide(n, i + 1)); /* check suivant */
}

/**
 *_sqrt_recursion - calcule la racine carree naturelle d'un nombre
 *@n: nombre dont on veut calculer la racine
 *
 *Return:
 *   - racine carree de n si elle existe
 *   - -1 si n < 0 ou pas de racine exacte
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_aide(n, 0));
}
