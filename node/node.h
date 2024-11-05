#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *parents[2];
    int number;
}
node;

node *generate_node(int number);
void print_node(node *n);
void free_memory(node *n);
