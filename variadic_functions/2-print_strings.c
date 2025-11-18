#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
* print_strings - imprime une chaine de caractere suivi d'une nouvelle ligne
* @separator: chaîne de caractères à imprimer entre les chaîne de
* caractères
* @n: nombre de chaîne de caractère passé par la fonctions
*
*/
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	char *str;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(ap, char *);

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(ap);
}
