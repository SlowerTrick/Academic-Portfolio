#include "node.h"

int main(void)
{
    node *n = generate_node(0);
    print_node(n);
    free_memory(n);
    return 0;
}