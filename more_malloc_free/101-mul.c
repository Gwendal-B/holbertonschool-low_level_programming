#include "main.h"
#include <stdlib.h>

/**
 * is_digit - Vérifie si une chaîne contient uniquement des chiffres
 * @s: chaîne à vérifier
 * Return: 1 si tous les caractères sont des chiffres, sinon 0
 */
int is_digit(char *s)
{
	int i = 0;

	if (!s || s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - Calcule la longueur d'une chaîne de caractères
 * @s: chaîne à mesurer
 * Return: longueur de la chaîne
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/**
 * print_error - Affiche "Error" suivi d'un retour à la ligne et quitte (98)
 */
void print_error(void)
{
	char *err = "Error\n";
	int i = 0;

	while (err[i])
	{
		_putchar(err[i]);
		i++;
	}
	exit(98);
}

/**
 * main - Multiplie deux nombres positifs donnés en arguments
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 * Return: 0 en cas de succès
 */
int main(int argc, char *argv[])
{
	char *n1, *n2;
	int len1, len2, *res, i, j, a, b, carry, sum, start = 0;

	if (argc != 3)
		print_error();
	n1 = argv[1];
	n2 = argv[2];
	if (!is_digit(n1) || !is_digit(n2))
		print_error();
	len1 = _strlen(n1);
	len2 = _strlen(n2);
	res = malloc(sizeof(int) * (len1 + len2));
	if (!res)
		return (1);
	for (i = 0; i < len1 + len2; i++)
		res[i] = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		a = n1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			b = n2[j] - '0';
			sum = a * b + res[i + j + 1] + carry;
			res[i + j + 1] = sum % 10;
			carry = sum / 10;
		}
		res[i + j + 1] += carry;
	}
	while (start < len1 + len2 && res[start] == 0)
		start++;
	if (start == len1 + len2)
		_putchar('0');
	else
		for (i = start; i < len1 + len2; i++)
			_putchar(res[i] + '0');
	_putchar('\n');
	free(res);
	return (0);
}

