#include "main.h"

int comp_count = 0;

void main(){

    int i, random;
    listint_t *my_list = NULL;
    setbuf(stdout, NULL);


    srand(918);
    random = rand() % 100;

    my_list = add_node(NULL,random);

    for (i = 0; i < 50; i++)
	{
		random = rand() % 100;
		add_node(my_list, random);
        printf("\n");
        print_list(my_list);
        printf("\n");
		printf("Comp Count: %i\n", comp_count);
		comp_count=0;
		
		printf("Node count: %i \n", count_nodes(my_list));
		//sleep(1);
	}
    free_list(my_list);

}

listint_t *add_node(listint_t *parent, int value)
{
    listint_t *node;

    if(!parent)
    {
        return (create_node(value));
    }
    printf("Compare Value %i to node with value %i ... ",value, parent->n);
    comp_count++;
    sleep(1);
    if (parent->n == value)
	{
		printf("They are equal, toss the value!\n");
		return (parent);
	}
    if (!parent->next)
    {
        printf("It's not in the list. Adding Node!\n");
        node=create_node(value);
        parent->next=node;
        return node;
    }
    printf("Check the next node!\n");
    return add_node(parent->next, value);

}

listint_t *create_node(int value)
{
    listint_t *node = malloc(sizeof(listint_t));
    if(!node)
    {
        printf("mem fail!\n");
        return (NULL);
    }
    node->n = value;
    node->next=NULL;
    return (node);
}

int count_nodes(listint_t *head)
{
    if(!head)
    {
        return (0);
    }
    return (1+ count_nodes(head->next));
}

void free_list(listint_t *head)
{
    if(!head)
    {
        return;
    }
    free_list(head->next);
    free(head);
}

void print_list(listint_t *head)
{
    if(!head)
    {
        printf("\n");
        return;
    }
    printf("%i\t",head->n);
    print_list(head->next);
}