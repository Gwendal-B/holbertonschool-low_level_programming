#include "main.h"

/**
 *_pow_recursion - calcule x a la puissance y
 *@x: base
 *@y: exposant
 *
 *Return:
 *   - x a la puissance y si y >= 0
 *   - -1 si y < 0
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
