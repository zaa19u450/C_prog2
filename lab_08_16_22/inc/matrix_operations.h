#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "main_header.h"

void add_matrix(int n, int m, double **ptrs1, double **ptrs2, double **ptrs_res);
void mult_matrix(int n1, int m1, int m2, double **ptrs1, double **ptrs2, double **ptrs_res);
double get_gaus_det(int n, double **ptrs);

#endif // MATRIX_OPERATIONS_H
