#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include "node.h"

node_t *matrix_read(FILE *f);
void matrix_print(FILE *f, node_t *head);

void matrix_free(node_t *head);
node_t *matrix_insert_end(node_t *head, node_t *node);

node_t *matrix_add(node_t *head1, node_t *head2);
node_t *matrix_mul(node_t *head1, node_t *head2);
node_t *matrix_delete_row_with_max(node_t *head);
int matrix_find_row_with_max(node_t *head);

#endif // MATRIX_H
