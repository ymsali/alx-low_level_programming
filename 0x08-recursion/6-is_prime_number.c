#include "main.h"

/**
 * divisors - Check if a number is divisible by another number
 * @n: The divisor
 * @m: The dividend
 *
 * Return: 0 if divisible, 1 if not divisible
 */
int divisors(int n, int m)
{
	if (m % n == 0)
	{
		return 0;
	}
	else if (m / 2 > n)
	{
		return divisors(n + 2, m);
	}
	else
	{
		return 1;
	}
}

/**
 * is_prime_number - Check if a number is prime
 * @n: The number to check
 *
 * Return: 1 if prime, 0 if not prime
 */
int is_prime_number(int n)
{
	if ((!(n % 2) && n != 2) || n < 2)
	{
		return 0;
	}
	else
	{
		return divisors(3, n);
	}
}
