#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a given index
 * @head: pointer to the head of the list
 * @index: position of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	/* Case 1: delete head */
	if (index == 0)
	{
		*head = temp->next;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		free(temp);
		return (1);
	}

	/* Move to the node at position index */
	while (temp != NULL && i < index)
	{
		temp = temp->next;
		i++;
	}

	/* If index out of bounds */
	if (temp == NULL)
		return (-1);

	/* Re-link neighbors */
	if (temp->prev != NULL)
		temp->prev->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	free(temp);
	return (1);
}
