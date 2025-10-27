#include "main.h"

/**
 *print_line - fait une ligne
 *@n: longueur de la ligne
 *
 *Return: R
 */
void print_line(int n)
{
	int i;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			_putchar('_');
		}
		_putchar('\n');
	}
}
