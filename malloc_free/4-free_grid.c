#include "main.h"
#include <stdlib.h>

/**
* free_grid - libere la memoire alloué au tableau 2D
* @grid: grille a liberer
* @height: nombre de ligne
*
* Return: Rien
*/
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		return;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
