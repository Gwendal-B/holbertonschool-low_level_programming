# Singly Linked Lists

Projet : implémentation et manipulation de listes chaînées simples en C.

## Description
Ce dépôt contient des exercices et utilitaires pour créer, parcourir, modifier et libérer des listes chaînées simples (singly linked lists). L'objectif est d'apprendre les opérations fondamentales sur les listes : insertion, suppression, recherche, inversion et libération de mémoire.

## Structure
- `*.c` : implémentations des fonctions.
- `*.h` : définitions de la structure et prototypes.
- `tests/` : exemples et petits programmes de validation (éventuel).
- `README.md` : ce fichier.

## Structure de données (exemple)
```c
#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct listint_s - Single linked list node
 * @n: integer
 * @next: pointe vers le prochain noeud
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

#endif /* LISTS_H */
```

## Fonctions courantes à implémenter
- Création et ajout :
  - add_nodeint
  - add_nodeint_end
- Accès et affichage :
  - print_listint
  - listint_len
- Suppression et libération :
  - pop_listint
  - free_listint
- Opérations avancées :
  - get_nodeint_at_index
  - sum_listint
  - insert_nodeint_at_index
  - delete_nodeint_at_index
  - reverse_listint

(Adaptez les noms et prototypes selon les consignes de l'exercice.)

## Compilation
Compiler avec les drapeaux de qualité :
```
gcc -Wall -Wextra -Werror -pedantic *.c -o executable
```

## Exemples d'utilisation
- Créer une liste, ajouter des éléments, afficher et libérer :
```c
listint_t *head = NULL;
add_nodeint_end(&head, 10);
add_nodeint_end(&head, 20);
print_listint(head);
free_listint(head);
```

## Bonnes pratiques
- Vérifier les retours d'allocation mémoire.
- Libérer toute la mémoire allouée.
- Respecter les prototypes et la signature des fonctions demandées.
- Utiliser des commentaires clairs et respecter les normes de style.

## Licence
Contenu libre à adapter pour les exercices pédagogiques.  
