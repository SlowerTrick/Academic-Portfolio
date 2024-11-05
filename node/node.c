#include "node.h"

node *generate_node(int number)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        exit(1);
    }
    n->number = number;
    n->parents[0] = malloc(sizeof(node));
    n->parents[1] = malloc(sizeof(node));
    n->parents[0]->number = number - 1;
    n->parents[1]->number = number + 1;
    n->parents[0]->parents[0] = NULL;
    n->parents[0]->parents[1] = NULL;
    n->parents[1]->parents[0] = NULL;
    n->parents[1]->parents[1] = NULL;
    return n;
}

void print_node(node *n)
{
    printf("Parent 1: %d\nParent 2: %d\nNumber: %d\n", n->parents[0]->number, n->parents[1]->number, n->number);
    return;
}

void free_memory(node *n)
{
    if (n->parents[0] == NULL)
    {
        free(n);
    }
    else
    {
        free_memory(n->parents[0]);
        free_memory(n->parents[1]);
        free(n);
    }
    return;
}