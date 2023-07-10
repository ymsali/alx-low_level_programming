#include <stdlib.h>
#include "main.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int flag = 0;
	int c;
	int w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return w;
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
		return NULL;

	int len = 0;
	while (str[len] != '\0')
		len++;

	int words = count_word(str);
	if (words == 0)
		return NULL;

	char **matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return NULL;

	int i, k = 0, c = 0, start = 0, end;

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c > 0)
			{
				end = i;
				char *tmp = malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
				{
					// Free memory if allocation fails
					for (int j = 0; j < k; j++)
						free(matrix[j]);
					free(matrix);
					return NULL;
				}

				int idx;
				for (idx = start; idx < end; idx++)
					tmp[idx - start] = str[idx];
				tmp[idx - start] = '\0';
				matrix[k] = tmp;
				k++;
				c = 0;
			}
		}
		else if (c == 0)
			start = i;

		if (str[i] != ' ')
			c++;
	}

	matrix[k] = NULL;

	return matrix;
}

