#include "lists.h"

/**
 * print_number - prints an unsigned int using _putchar
 * @n: number to print
 */
void print_number(unsigned int n)
{
	char buffer[10];
	int i = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		_putchar(buffer[i]);
}

/**
 * print_str - prints a string or (nil) if NULL
 * @s: string to print
 */
void print_str(char *s)
{
	unsigned int i = 0;

	if (!s)
	{
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
		return;
	}
	while (s[i])
		_putchar(s[i++]);
}

/**
 * print_list - prints all elements of a list_t
 * @h: head of the list
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		_putchar('[');
		print_number(h->len);
		_putchar(']');
		_putchar(' ');
		print_str(h->str);
		_putchar('\n');
		count++;
		h = h->next;
	}
	return (count);
}
