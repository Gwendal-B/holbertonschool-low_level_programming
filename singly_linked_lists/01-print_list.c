#include "lists.h"

/**
 * print_list - prints all elements of a singly linked list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;
	const char *str;
	unsigned int i, len;
	char num[12]; /* pour convertir len en caractères */
	int j;

	while (h)
	{
		len = h->len;
		/* Affiche la longueur entre crochets : [len] */
		if (len == 0)
			_putchar('0');
		else
		{
			j = 0;
			while (len > 0)
			{
				num[j++] = (len % 10) + '0';
				len /= 10;
			}
			_putchar('[');
			while (--j >= 0)
				_putchar(num[j]);
			_putchar(']');
		}

		_putchar(' ');

		str = h->str;
		if (str)
		{
			for (i = 0; i < h->len; i++)
				_putchar(str[i]);
		}
		else
		{
			_putchar('(');
			_putchar('n');
			_putchar('i');
			_putchar('l');
			_putchar(')');
		}
		_putchar('\n');
		count++;
		h = h->next;
	}

	return (count);
}
