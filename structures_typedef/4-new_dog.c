#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
* new_dog - nouveau chien
* @name: nom du chien
* @age: age du chien
* @owner: proprietaire du chien
*
* Return: pointeur vers le nouveau chien, NULL si echec
*/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int i, lname = 0, lowner = 0;

	if (!name || !owner)
		return (NULL);

	while (name[lname])
		lname++;
	while (owner[lowner])
		lowner++;
	d = malloc(sizeof(dog_t));
	if (!d)
		return (NULL);

	d->name = malloc(lname + 1);
	d->owner = malloc(lowner + 1);

	if (!d->name || !d->owner)
	{
		free(d->name);
		free(d->owner);
		free(d);
		return (NULL);
	}
	for (i = 0; i <= lname; i++)
		d->name[i] = name[i];
	for (i = 0; i <= lowner; i++)
		d->owner[i] = owner[i];
	d->age = age;

	return (d);
}
