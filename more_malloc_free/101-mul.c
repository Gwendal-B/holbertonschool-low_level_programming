#include "main.h"
#include <stdlib.h>

/**
 * _isdigit_str - vérifie si une chaîne contient uniquement des chiffres
 * @s: chaîne à vérifier
 * Return: 1 si la chaîne est numérique, 0 sinon
 */
int _isdigit_str(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - retourne la longueur d'une chaîne
 * @s: chaîne
 * Return: longueur
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * print_error - affiche "Error" et quitte
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
 * main - multiplie deux nombres positifs
 * @argc: nombre d’arguments
 * @argv: tableau d’arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, *res, n1, n2, carry, sum, start = 0;
	if (argc != 3)
		print_error();
	num1 = argv[1];
	num2 = argv[2];

	if (!_isdigit_str(num1) || !_isdigit_str(num2))
		print_error();

	len1 = _strlen(num1);
	len2 = _strlen(num2);

	res = malloc(sizeof(int) * (len1 + len2));
	if (!res)
		return (1);
	for (i = 0; i < len1 + len2; i++)
		res[i] = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + res[i + j + 1] + carry;
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
	{
		for (; start < len1 + len2; start++)
			_putchar(res[start] + '0');
	}
	_putchar('\n');
	free(res);
	return (0);
}
