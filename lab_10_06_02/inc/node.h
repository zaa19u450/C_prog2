#ifndef NODE_H
#define NODE_H

#include <stdio.h>

typedef struct node node_t;

struct node
{
    int i;
    int j;
    int value;
    node_t *next;
};

node_t *node_create(int i, int j, int value);
void node_free(node_t *node);

void node_print(FILE *f, node_t *node);

#endif // NODE_H
