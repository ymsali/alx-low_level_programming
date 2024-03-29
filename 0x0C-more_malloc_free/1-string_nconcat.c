#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * @n: amount of bytes.
 *
 * Return: pointer to the allocated memory.
 * if malloc fails, status value is equal to 98.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *sout;
	unsigned int ls1, ls2, lsout, i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	ls1 = strlen(s1);
	ls2 = strlen(s2);

	if (n > ls2)
		n = ls2;

	lsout = ls1 + n;

	sout = malloc((lsout + 1) * sizeof(char));

	if (sout == NULL)
		return (NULL);

	for (i = 0; i < lsout; i++)
	{
		if (i < ls1)
			sout[i] = s1[i];
		else
			sout[i] = s2[i - ls1];
	}

	sout[i] = '\0';

	return (sout);
}

