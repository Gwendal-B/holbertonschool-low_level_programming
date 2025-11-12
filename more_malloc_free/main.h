#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int *array_range(int min, int max);
int is_digit(char *s);
int _strlen(char *s);
void print_error(void);
int main(int argc, char *argv[]);
int trouver_longueur(char *str);
char *creer_tableau_x(int size);
char *ignorer_zero_initiaux(char *str);
int obtenir_chiffre(char c);
void obtenir_produit(char *produit, char *mult, int digit, int zeroes);
void ajouter_nombres(char *produit_final, char *produit_suivant, int taille_suivant);

#endif /* MAIN_H */
