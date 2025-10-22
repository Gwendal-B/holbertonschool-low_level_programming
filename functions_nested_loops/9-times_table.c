#include "main.h"

/**
 *times_table - afficher les tables de multiplications de 1 a 9
 */
void times_table(void)
{
	int a, b, result;

	for (a = 0; a <= 9 ; a++)
	{
		for (b = 0; b <= 9 ; b++)
		{
			result = a * b;
			if (b != 0)
			{
				_putchar(',');
				_putchar(' ');

				if (result < 10)
					_putchar(' ');
			}

			if (result < 10)
				_putchar(result + '0');

			else
			{
				_putchar((result / 10) + '0');
				_putchar((result % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
