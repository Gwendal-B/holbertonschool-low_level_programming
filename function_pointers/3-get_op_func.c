#include "3-calc.h"
#include <stddef.h>

/**
* get_op_func - selectionne la bonne fonction selon l'operateur
* @s: operateur donné (+, -, *, /, %)
*
* Return: pointeur vers la fonction correspondante ou NULL si inconnu
*/
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	while (ops[i].op != NULL)
	{
		if (*(ops[i].op) == *s && s[1] == '\0')
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
