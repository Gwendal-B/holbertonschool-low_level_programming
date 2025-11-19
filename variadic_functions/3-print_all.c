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

/**
 * print_all - Affiche une liste d’arguments de types variés
 * @format: chaîne indiquant les types des arguments passés
 *
 * Description:
 *  - 'c' : caractère
 *  - 'i' : entier
 *  - 'f' : float (double lors du va_arg)
 *  - 's' : chaîne (si NULL -> "(nil)")
 *
 *  Chaque valeur est séparée par ", " si un autre élément suit.
 *  Comporte une structure de correspondance pour éviter les switchs.
 */
void print_all(const char * const format, ...)
{
	printer_t funcs[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string}
	};

	va_list ap;
	int i = 0, j;
	char *sep = "";

	va_start(ap, format);

	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == funcs[j].symbol)
			{
				printf("%s", sep);
				funcs[j].print(ap);
				sep = ", ";
				break;
			}
			j++;
		}
		i++;
	}

	printf("\n");
	va_end(ap);
}
