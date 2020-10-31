#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>
#include <assert.h>
#include "main_header.h"
#include "alloc_free.h"
#include "matrix_io.h"
#include "matrix_operations.h"

int check_dm_eq(int n1, int m1, int n2, int m2, double **ptrs1, double **ptrs2);

Suite *allocate_matrix_suite(void);
Suite *input_dm_from_file_suite(void);
Suite *output_dm_to_file_suite(void);
Suite *add_matrix_suite(void);
Suite *mult_matrix_suite(void);
Suite *get_gaus_det_suite(void);

#endif // CHECK_MAIN_H
