#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: width of the array.
 * @height: height of the array.
 *
 * Return: Pointer to a 2D array of integers.
 * If width or height is less than 1, returns NULL.
 * If malloc fails during allocation, returns NULL.
 */
int **alloc_grid(int width, int height)
{
	if (width < 1 || height < 1)
		return NULL;

	int **gridout = malloc(height * sizeof(int *));
	if (gridout == NULL)
		return NULL;

	int i, j;
	for (i = 0; i < height; i++)
	{
		gridout[i] = malloc(width * sizeof(int));
		if (gridout[i] == NULL)
		{
			for (int k = 0; k < i; k++)
				free(gridout[k]);
			free(gridout);
			return NULL;
		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			gridout[i][j] = 0;

	return gridout;
}

