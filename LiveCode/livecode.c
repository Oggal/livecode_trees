#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * main - Entry Point
 * Return: 0
 */
void main(void)
{
	int i, random;
	binary_tree_t *tree;
	setbuf(stdout, NULL);

	srand(918); /* Set seed for rand */
	random = rand() % 100; /* Set Random to a random Number between 0 and 99 */

	/* Add 10 numbers to our Binary Tree */
	tree = add_node(NULL, random);
	binary_tree_print(tree);

	for (i = 0; i < 50; i++)
	{
		random = rand() % 100;
		add_node(tree, random);
		binary_tree_print(tree);

		printf("Node count: %i \n", count_nodes(tree));

	}
	//free_tree(tree);
}

