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
 * multiply_digits - Multiplie deux nombres positifs stockés en chaînes
 * @n1: premier nombre
 * @n2: deuxième nombre
 * @res: tableau pour stocker le résultat
 * @len1: longueur de n1
 * @len2: longueur de n2
 */
void multiply_digits(char *n1, char *n2, int *res, int len1, int len2)
{
	int i, j, a, b, sum, carry;

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
}

/**
 * print_result - Affiche le résultat contenu dans le tableau
 * @res: tableau contenant le résultat
 * @size: taille du tableau
 */
void print_result(int *res, int size)
{
	int i = 0;

	while (i < size && res[i] == 0)
		i++;
	if (i == size)
		_putchar('0');
	else
		for (; i < size; i++)
			_putchar(res[i] + '0');
	_putchar('\n');
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
	int *res, len1, len2, i;

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

	multiply_digits(n1, n2, res, len1, len2);
	print_result(res, len1 + len2);

	free(res);
	return (0);
}
