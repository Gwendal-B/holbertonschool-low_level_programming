#include "main.h"

/**
 *_puts_recursion - affiche une chaine avec recursion
 *@s: chaine a afficher
 */
void _puts_recursion(char *s)
{
	if (*s == '\0') /* base case */
	{
		_putchar('\n');
		return;
	}

	_putchar(*s);
	_puts_recursion(s + 1); /* appel récursif sur la suite */
}

