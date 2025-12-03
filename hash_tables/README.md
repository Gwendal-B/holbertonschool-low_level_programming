# Hash Tables - Holberton School (low_level_programming)

Description
---
Ce projet implémente une table de hachage en C pour stocker et récupérer des paires clé/valeur efficacement. L'objectif est de comprendre les fonctions de hachage, la gestion des collisions et l'organisation mémoire en C.

Fonctionnalités principales
---
- Création et destruction d'une table de hachage.
- Insertion (set) et lecture (get) de paires clé/valeur.
- Gestion des collisions (liste chaînée par emplacement).
- Fonction de hachage (ex. djb2) et calcul d'index.
- Affichage de la table pour debug.

Structure du projet
---
- README.md — ce fichier.
- *.c — implémentations (create, set, get, delete, hash, index, print).
- *.h — prototypes et définitions de structures (hash_table_t, hash_node_t).
- tests/ — (optionnel) exemples et tests unitaires.
- main.c — exemple d'utilisation (optionnel).

Fonctions attendues (exemples)
---
- hash_table_t *hash_table_create(unsigned long int size);
- unsigned long int hash_djb2(const unsigned char *str);
- unsigned long int key_index(const unsigned char *key, unsigned long int size);
- int hash_table_set(hash_table_t *ht, const char *key, const char *value);
- char *hash_table_get(const hash_table_t *ht, const char *key);
- void hash_table_print(const hash_table_t *ht);
- void hash_table_delete(hash_table_t *ht);

Compilation
---
Compiler avec les avertissements recommandés :
```
gcc -Wall -Wextra -Werror -pedantic *.c -o hash_table
```

Exemple d'utilisation
---
1. Compiler :
```
gcc -Wall -Wextra -Werror -pedantic *.c -o hash_table
```
2. Exécuter (si main.c fourni) :
```
./hash_table
```
3. Exemple minimal (dans main.c) :
```c
hash_table_t *ht = hash_table_create(1024);
hash_table_set(ht, "school", "Holberton");
printf("%s\n", hash_table_get(ht, "school")); /* affiche: Holberton */
hash_table_delete(ht);
```

Bonnes pratiques
---
- Valider les entrées (clé non-NULL et non-vide).
- Dupliquer les chaînes (strdup) pour gérer la durée de vie des valeurs.
- Libérer correctement toute la mémoire lors de la suppression.
- Tester les collisions en insérant plusieurs clés produisant le même index.

Tests
---
Ajouter des tests unitaires pour :
- Création/suppression de table.
- Insertion et mise à jour d'une clé existante.
- Récupération d'une clé inexistante.
- Gestion des collisions (plusieurs éléments au même index).

Licence et auteur
---
Auteur: Étudiant Holberton  
Licence: MIT (ou autre licence choisie)

Contact
---
Pour questions ou contributions, ouvrir une issue ou un pull request dans le dépôt.
