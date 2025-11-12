#include "dog.h"
#include <stdio.h>

/**
* init_dog - initialise une structure
* @d: pointe vers la structure a initialiser
* @name: nom du chien
* @age: age du chien
* @owner: nom du proprietaire
*
* Description: cette fo,ction remplit les champs d'une
* structure passé en argument
*/

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
