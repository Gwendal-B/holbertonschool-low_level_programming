#include "main.h"

/**
 * cap_string - met en majuscule la première lettr
 * @s: chaînea  modifier
 *
 * Return: pointeur vers la chaîne modifiée
 */
char *cap_string(char *s)
{
	int i = 0;
	int separateur = 1;

	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
				s[i] == ',' || s[i] == ';' || s[i] == '.' ||
				s[i] == '!' || s[i] == '?' || s[i] == '"' ||
				s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}')
		{
			separateur = 1;
		}
		else if (separateur && s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
			separateur = 0;
		}
		else
		{
			separateur = 0;
		}
		i++;
	}

	return (s);
}
