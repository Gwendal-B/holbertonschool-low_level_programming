#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/**
 * is_digit_str - vérifie si une chaîne contient uniquement des chiffres
 * @s: chaîne à vérifier
 *
 * Return: 1 si la chaîne contient uniquement des chiffres, sinon 0
 */
int is_digit_str(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (!isdigit(s[i]))
			return (0);
	}
	return (1);
}

/**
 * print_error - affiche "Error" et quitte avec le code 98
 */
void print_error(void)
{
	printf("Error\n");
	return (98);
}

/**
 * main - multiplie deux nombres positifs passés en arguments
 * @argc: nombre d'arguments
 * @argv: tableau des arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, *result, i, j, carry, n1, n2, sum;

	if (argc != 3)
		print_error();
	num1 = argv[1];
	num2 = argv[2];
	if (!is_digit_str(num1) || !is_digit_str(num2))
		print_error();
	len1 = strlen(num1);
	len2 = strlen(num2);
	result = calloc(len1 + len2, sizeof(int));
	if (!result)
		return (1);
	for (i = len1 - 1; i >= 0; i--)/*Multiplication des chiffres*/
	{
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			result[i + j + 1] = sum % 10;
			carry = sum / 10;
		}
		result[i + j + 1] += carry;
	}
	i = 0;/*Affichage du résultat*/
	while (i < len1 + len2 && result[i] == 0)
		i++; /*Ignorer les zéros de tête*/
	if (i == len1 + len2) /* résultat = 0 */
		_putchar('0');
	else
	{
		for (; i < len1 + len2; i++)
			_putchar(result[i] + '0');
	}
	_putchar('\n');
	free(result);
	return (0);
}
