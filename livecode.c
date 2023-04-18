#include "main.h"
#include <unistd.h>

/**
 * main - Entry Point
 * Return: 0
 */
int main(void)
{
	int i, random;
	binary_tree_t *tree;

	srand(918); /* Set seed for rand */
	random = rand() % 100; /* Set Random to a random Number between 0 and 99 */
	// printf("number: %i", random);
	/* Add 10 numbers to our Binary Tree */
	tree = add_node(NULL, random);
	binary_tree_print(tree);

	for (i = 0; i < 260; i++)
	{
		random = rand() % 500;
		add_node(tree, random);
		binary_tree_print(tree);

		printf("Node count: %i \n", count_nodes(tree));
		//eep(1);
	}

	return (0);
}


binary_tree_t *add_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if(!parent)
	{
		return (create_node(value));
	}

	if (parent->n == value)
		return (parent);

	if (value < parent->n)
	{
		if (parent->left == NULL)
		{
			node = create_node(value);
			node->parent = parent;
			parent->left = node;
			return (node);
		} else {
			return (add_node(parent->left, value));
		}
	}else {
		if (parent->right == NULL)
		{
			node = create_node(value);
			node->parent = parent;
			parent->right = node;
			return (node);
		} else {
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
