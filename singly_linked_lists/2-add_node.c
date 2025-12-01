#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t
 * @head: pointer to the head of the list
 * @str: string to store in the new node
 *
 * Return: address of the new element, or NULL on failure
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len = 0;

	while (str[len])
		len++;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = malloc(len + 1);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	for (len = 0; str[len]; len++)
		new->str[len] = str[len];
	new->str[len] = '\0';
	new->len = len;
	new->next = *head;
	*head = new;

	return (new);
}
