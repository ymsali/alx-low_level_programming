#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - adds positive numbers.
 * @argc: number of command line arguments.
 * @argv: array that contains the program command line arguments.
 * Return: 0 - success.
 */

int main(int argc, char *argv[])
{
    int add = 0;

    for (int i = 1; i < argc; i++)
    {
        char *current = argv[i];
        while (*current != '\0')
        {
            if (!isdigit(*current))
            {
                printf("Error\n");
                return 1;
            }
            current++;
        }
        add += atoi(argv[i]);
    }

    printf("%d\n", add);
    return 0;
}

