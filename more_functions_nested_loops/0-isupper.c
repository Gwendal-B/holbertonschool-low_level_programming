#include "main.h"

/**
 *_isupper - verifie si c'est une maj ou non
 *@c : valeur a tester
 *
 *Return: 1 si maj 0 sinon
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
