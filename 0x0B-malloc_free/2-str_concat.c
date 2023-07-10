#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 *
 * Return: Pointer to a new concatenated string.
 * If malloc fails, returns NULL.
 */
char *str_concat(char *s1, char *s2)
{
	char *strout;
	unsigned int i, j, k;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		;

	for (j = 0; s2[j] != '\0'; j++)
		;

	strout = malloc(sizeof(char) * (i + j + 1));

	if (strout == NULL)
		return (NULL);

	for (k = 0; k < i; k++)
		strout[k] = s1[k];

	for (j = 0; j <= j; j++, k++)
		strout[k] = s2[j];

	strout[k] = '\0';

	return (strout);
}

