#include "main.h"
#include <unistd.h>
#include <stdio.h>

int comp_count = 0;

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
		random = rand() % 500;
		add_node(tree, random);
		//binary_tree_print(tree);
		printf("Comp Count: %i\n", comp_count);
		comp_count=0;
		
		printf("Node count: %i \n", count_nodes(tree));

	}

}


binary_tree_t *add_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if(!parent)
	{
		return (create_node(value));
	}

	printf("Compare Value %i to node with value %i ... ",value, parent->n);
	comp_count++;

	if (parent->n == value)
	{
		printf("They are equal, toss the value!\n");
		return (parent);
	}
	sleep(1);
	if (value < parent->n)
	{
		printf("Check the left...");
		if (parent->left == NULL)
		{
			printf("Insert Here!\n");
			node = create_node(value);
			node->parent = parent;
			parent->left = node;
			return (node);
		} else {
			printf("\n");
			return (add_node(parent->left, value));
		}
	}else {
		printf("Check the right...");
		if (parent->right == NULL)
		{
			printf("Insert Here!\n");
			node = create_node(value);
			node->parent = parent;
			parent->right = node;
			return (node);
		} else {
			printf("\n");
			return (add_node(parent->right, value));
		}
	}
}


binary_tree_t *create_node(int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node){
		printf("Mem Fail");
		return(NULL);
	}
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	return (node);
}

int count_nodes(binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (count_nodes(tree->left) + count_nodes(tree->right) + 1);
}
