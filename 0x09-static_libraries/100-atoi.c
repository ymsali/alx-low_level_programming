#include <stdio.h>

/**
 * _atoi - a function that converts a string to an integer
 * @s: An input string
 *
 * Description: This function converts a string to an integer.
 * The number in the string can be preceded by an infinite number of characters.
 * It takes into account all the '-' and '+' signs before the number.
 * If there are no numbers in the string, the function returns 0.
 * The function does not use the 'long' type or declare new variables of "type" array.
 * The code is compiled with the '-fsanitize=signed-integer-overflow' flag.
 * Note: The standard library provides a similar function: atoi.
 *
 * Return: The integer from conversion
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char null_flag = 0;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
		{
			null_flag = 1;
			total = total * 10 + (*s - '0');
		}
		else if (null_flag)
		{
			break;
		}
		s++;
	}

	if (sign < 0)
		total = -total;

	return total;
}

