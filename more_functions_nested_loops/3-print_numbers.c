#include "main.h"

/**
 *print_numbers - imprime les chiffres de 1 a 9
 *
 *Return: R
 */
void print_numbers(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		_putchar(i + '0');
	}
	_putchar('\n');
}
