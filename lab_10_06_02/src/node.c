#include "node.h"
#include "main_header.h"
#include <stdlib.h>

node_t *node_create(int i, int j, int value)
{
    node_t *node = NULL;

    node = malloc(sizeof(node_t));
    if (node)
    {
        node->i = i;
        node->j = j;
        node->value = value;
        node->next = NULL;
    }
    return node;
}

void node_free(node_t *node)
{
    free(node);
}

void node_print(FILE *f, node_t *node)
{
    fprintf(f, "%d %d %d ", node->i, node->j, node->value);
}
