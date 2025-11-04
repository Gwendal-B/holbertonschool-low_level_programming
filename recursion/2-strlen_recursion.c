#include "main.h"

/**
 *_strlen_recursion - calcule la longueur d'une chaine
 *@s: chaine a mesurer
 *Return: longueur de la chaine
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}
