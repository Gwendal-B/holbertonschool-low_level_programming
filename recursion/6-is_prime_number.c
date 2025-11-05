#include "main.h"

/**
 *_is_prime_aide - verifie si n est divisible par i
 *@n: nombre a tester
 *@i: diviseur candidat
 *
 * Return:
 *   - 1 si n est premier
 *   - 0 sinon
 */
int _is_prime_aide(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (_is_prime_aide(n, i + 1));
}

/**
 * is_prime_number - verifie si un nombre est premier
 * @n: nombre a tester
 *
 * Return:
 *   - 1 si n est premier
 *   - 0 sinon
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (_is_prime_aide(n, 2));
}
