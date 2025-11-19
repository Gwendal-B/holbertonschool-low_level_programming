#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_char - Affiche un caractère
 * @ap: liste d’arguments contenant le caractère (promu en int)
 */
void print_char(va_list ap)
{
	printf("%c", va_arg(ap, int));
}

/**
 * print_int - Affiche un entier
 * @ap: liste d’arguments contenant l’entier
 */
void print_int(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * print_float - Affiche un flottant
 * @ap: liste d’arguments contenant le flottant (promu en double)
 */
void print_float(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * print_string - Affiche une chaîne de caractères
 * @ap: liste d’arguments contenant la chaîne
 *
 * Description:
 *  Si la chaîne vaut NULL, affiche "(nil)"
 */
void print_string(va_list ap)
{
	char *s = va_arg(ap, char *);

	if (s == NULL)
	{
		printf("(nil)");
		return;
	}

	printf("%s", s);
}
