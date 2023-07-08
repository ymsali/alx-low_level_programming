#include "main.h"

/**
 * _strspn - Calculates the length of the initial segment of s
 *            which consists only of bytes from accept.
 * @s: Segment to be targeted.
 * @accept: Reference bytes container.
 *
 * Return: The number of bytes in the initial segment of s
 *         consisting only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int bytes = 0;
    int i;

    while (*s)
    {
        for (i = 0; accept[i]; i++)
        {
            if (accept[i] == *s)
            {
                bytes++;
                break;
            }
            else if (accept[i + 1] == '\0')
                return bytes;
        }
        s++;
    }

    return bytes;
}

