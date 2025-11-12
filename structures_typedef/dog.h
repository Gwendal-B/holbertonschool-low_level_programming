#ifndef DOG_H
#define DOG_H

/**
* struct dog - A structure representant un chien
* @name: nom du chien
* @age: age du chien
* @owner: proprietaire du chien
*
* Description: Cette structure contient des informations sur un chien,
*y compris son nom, son age et le nom de son proprietaire.
*/
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */
