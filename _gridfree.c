#include "simple_shell.h"
/**
 * _gridfree - frees mem allocated in a prev exercise using malloc
 * @grid: double pointer to the grid(2D array)
 * @height: height/rows of the grid
 */

void _gridfree(char **grid, int height)
{
	int r;

	if (grid == NULL)
		return;
	for (r = 0; r < height; r++)
	{
		free(grid[r]);
	}
}
