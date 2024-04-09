#ifndef LIVE_CODE
#define LIVE_CODE

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;

void binary_tree_print(const binary_tree_t *);

binary_tree_t *add_node(binary_tree_t *parent, int value);
binary_tree_t *create_node(int value);
int count_nodes(binary_tree_t *tree);

void free_tree(binary_tree_t *tree);
#endif
