#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * is_zero - determines if a number is zero
 * @num: number as a string
 *
 * Return: 1 if the number is zero, 0 otherwise.
 */
int is_zero(const char *num)
{
	for (int i = 0; num[i] != '\0'; i++)
	{
		if (num[i] != '0')
			return 0;
	}

	return 1;
}

/**
 * initialize_array - initializes an array with zeros
 * @arr: array to initialize
 * @length: length of the array
 *
 * Return: pointer to the initialized array.
 */
char *initialize_array(char *arr, int length)
{
	for (int i = 0; i < length; i++)
		arr[i] = '0';

	arr[length] = '\0';
	return arr;
}

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
 * main - Entry point.
 * A program that multiplies two positive numbers.
 * @argc: number of arguments.
 * @argv: arguments vector.
 *
 * Return: 0 - success.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	int length1 = check_number(argv[1]);
	int length2 = check_number(argv[2]);

	if (is_zero(argv[1]) || is_zero(argv[2]))
	{
		printf("0\n");
		return 0;
	}

	int outputLength = length1 + length2;
	char *output = malloc((outputLength + 1) * sizeof(char));

	if (output == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	initialize_array(output, outputLength);

	int k = outputLength - 1;
	int i = length1 - 1;
	int j = length2 - 1;
	int carry = 0;
	int add;

	for (; k >= 0; k--, i--)
	{
		if (i < 0)
		{
			if (carry > 0)
			{
				add = (output[k] - '0') + carry;

				if (add > 9)
					output[k - 1] = (add / 10) + '0';

				output[k] = (add % 10) + '0';
			}

			i = length1 - 1;
			j--;
			carry = 0;
			k = outputLength - (1 + j);
		}

		if (j < 0)
		{
			if (output[0] != '0')
				break;

			outputLength--;
			free(output);
			output = malloc((outputLength + 1) * sizeof(char));
			initialize_array(output, outputLength);
			k = outputLength - 1;
			i = length1 - 1;
			j = length2 - 1;
			carry = 0;
		}

		if (j >= 0)
		{
			add = ((argv[1][i] - '0') * (argv[2][j] - '0')) + (output[k] - '0') + carry;
			carry = add / 10;
			output[k] = (add % 10) + '0';
		}
	}

	printf("%s\n", output);
	free(output);

	return 0;
}

