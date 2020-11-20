#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>
#include <stdlib.h>
#include "node.h"
#include "matrix.h"


int matrix_eq(node_t *head1, node_t *head2);

Suite *node_create_suite(void); //also checks node_free

Suite *matrix_read_suite(void); //also checks matrix_free

Suite *matrix_insert_end_suite(void);

Suite *matrix_add_suite(void);

Suite *matrix_mul_suite(void);

Suite *matrix_delete_row_with_max_suite(void); //also checks matrix_find_row_with_max


#endif // CHECK_MAIN_H
