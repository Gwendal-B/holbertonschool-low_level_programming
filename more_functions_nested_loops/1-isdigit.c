#include "main.h"

/**
 *_isdigit - verifie si c'est un chiffre
 *@c : valeur en question
 *
 *Return: 1 si c'est un chiffre 0 sinon
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
