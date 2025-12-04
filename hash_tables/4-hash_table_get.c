#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: the hash table
 * @key: the key to search for
 *
 * Return: the value associated with the key,
 *         or NULL if key wasn’t found or table is invalid
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	index = 0;
	if (!ht || !key || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}
