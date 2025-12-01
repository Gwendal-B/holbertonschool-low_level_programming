# Doubly linked lists

Petit projet C pour implémenter et manipuler des listes doublement chaînées (doubly linked lists).

## Description
Ce dépôt contient les structures et fonctions de base pour créer, parcourir et modifier une liste doublement chaînée en C. Objectifs : compréhension des pointeurs, allocation dynamique, et gestion de la mémoire.

## Prérequis
- Compilateur C (gcc)
- Outils de vérification mémoire (valgrind) recommandés

## Compilation
Exemple de compilation générale :
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o test
```

## Structure du projet (exemples de fichiers)
- dlistint.h — définition du type et prototypes
- 0-print_dlistint.c — afficher les éléments
- 1-dlistint_len.c — longueur de la liste
- 2-add_dnodeint.c — ajouter un noeud au début
- 3-add_dnodeint_end.c — ajouter un noeud à la fin
- 4-free_dlistint.c — libérer la liste
- 5-get_dnodeint.c — récupère le noeud à un index
- 6-insert_dnodeint.c — insérer à un index donné
- 7-delete_dnodeint.c — supprimer un noeud à un index
- tests/ — tests et exemples d'utilisation

## Type principal
Prototype typique dans dlistint.h :
```c
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;
```

## Fonctions disponibles (exemples)
- size_t print_dlistint(const dlistint_t *h);
- size_t dlistint_len(const dlistint_t *h);
- dlistint_t *add_dnodeint(dlistint_t **head, const int n);
- dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
- void free_dlistint(dlistint_t *head);
- dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
- dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
- int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

Chaque fonction doit gérer correctement les allocations, les erreurs et mettre à jour prev/next.

## Tests et validation
- Compiler les exemples dans tests/ puis exécuter.
- Utiliser valgrind pour détecter les fuites :
```
valgrind --leak-check=full ./test
```

## Bonnes pratiques
- Vérifier les retours de malloc.
- Toujours mettre prev/next à NULL quand nécessaire.
- Libérer toute la mémoire allouée.

## Licence
MIT

Voilà un README minimal et fonctionnel pour démarrer le projet de listes doublement chaînées.
