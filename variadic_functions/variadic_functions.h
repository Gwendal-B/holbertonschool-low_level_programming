#ifndef VARIADIC_FUNCTIONS
#define VARIADIC_FUNCTIONS

#include <stdarg.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

/**
 * struct printer - Associe un type à une fonction d'affichage
 * @symbol: symbole représentant le type (c, i, f, s)
 * @print: fonction correspondante pour afficher ce type
 */
typedef struct printer
{
	char symbol;
	void (*print)(va_list);
} printer_t;

void print_all(const char * const format, ...);

#endif /*VARIADIC_FUNCTIONS*/
