#include "function_pointers.h"
#include <stddef.h>

/**
* print_name - applique une fonction sur un nom
* @name: nom a afficher
* @f: fonction prenant un char * en parametre
*
* Return: Rien
*/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
