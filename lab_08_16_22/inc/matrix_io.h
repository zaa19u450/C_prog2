#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include "main_header.h"
#include "alloc_free.h"

int input_dm_from_file(char filename[], double ***ptrs, int *n_return, int *m_return);
void output_dm_to_file(FILE *f, int n, int m, double **ptrs);

#endif // MATRIX_IO_H
