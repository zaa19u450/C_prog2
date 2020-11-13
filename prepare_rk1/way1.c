//Матрица как одномерный массив
#include <stdlib.h>
#include "main_header.h"

int allocate_matrix1(int **data, int n, int m)
{
    int *data_tmp;
    data_tmp = calloc(n * m, sizeof(int));
    if (data_tmp)
    {
        *data = data_tmp;
        return OK;
    }
    else
        return ERRMEM;
}

void free_matrix1(int *data)
{
    free(data);
}
