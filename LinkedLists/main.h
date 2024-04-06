#ifndef LIVE_CODE
#define LIVE_CODE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

listint_t *add_node(listint_t *parent, int value);
listint_t *create_node(int value);
int count_nodes(listint_t *headNode);

void print_list(listint_t *headNode);
void free_list(listint_t *headNode);
#endif