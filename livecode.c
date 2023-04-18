#include "main.h"

/**
 * main - Entry Point
 * Return: 0
 */
int main(void)
{
	int i, random;

	srand(918); /* Set seed for rand */
	random = rand() % 100 /* Set Random to a random Number between 0 and 99 */
	printf("number: %i", random);
	/* Add 10 numbers to our Binary Tree */

	return (0);
}
