#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * check_number - checks if a string represents a valid number in base 10
 * @num: number as a string
 *
 * Return: length of the number.
 * If the number is invalid, it prints an error message and exits with status 98.
 */
int check_number(const char *num)
{
    int length = strlen(num);

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(num[i]))
        {
            printf("Error\n");
            exit(98);
        }
    }

    return length;
}

/**
 * multiply - multiplies two positive numbers represented as strings
 * @num1: first number
 * @num2: second number
 *
 * Return: pointer to the result as a string.
 */
char *multiply(const char *num1, const char *num2)
{
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    int outputLength = length1 + length2;
    int *output = calloc(outputLength, sizeof(int));

    if (output == NULL)
    {
        printf("Error\n");
        exit(98);
    }

    for (int i = length1 - 1; i >= 0; i--)
    {
        for (int j = length2 - 1; j >= 0; j--)
        {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            int product = digit1 * digit2;

            int currentIndex = i + j + 1;
            int carry = product / 10;
            int remainder = product % 10;

            output[currentIndex] += remainder;
            output[currentIndex - 1] += carry;

            // Handle carry
            int k = currentIndex - 1;
            while (output[k] >= 10)
            {
                carry = output[k] / 10;
                remainder = output[k] % 10;
                output[k] = remainder;
                output[k - 1] += carry;
                k--;
            }
        }
    }

    char *result = malloc((outputLength + 1) * sizeof(char));

    if (result == NULL)
    {
        printf("Error\n");
        exit(98);
    }

    for (int i = 0; i < outputLength; i++)
        result[i] = output[i] + '0';

    result[outputLength] = '\0';

    free(output);

    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error\n");
        return 98;
    }

    int length1 = check_number(argv[1]);
    int length2 = check_number(argv[2]);

    if (length1 == 0 || length2 == 0)
    {
        printf("Error\n");
        return 98;
    }

    char *result = multiply(argv[1], argv[2]);

    printf("%s\n", result);

    free(result);

    return 0;
}
