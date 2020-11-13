//Объединение подходов (1) - массив указателей, а сама матрица - одномерный массив
#include <stdlib.h>
#include "main_header.h"

//Выход: указатель на массив строк матрицы (p)
//следить за первым!
int allocate_matrix3(int ***ptrs, int n, int m)
{
    int *matrix = NULL;
    int **ptrs_tmp = NULL;

    ptrs_tmp = calloc(n, sizeof(int *));
    if (ptrs_tmp == NULL)
        return ERRMEM;
    matrix = calloc(n * m, sizeof(int));
    if (matrix == NULL)
    {
        free(ptrs_tmp);
        return ERRMEM;
    }
    for (int i = 0; i < n; i++)
        ptrs_tmp[i] = matrix + (i *m);
    *ptrs = ptrs_tmp;
    return OK;
}

void free_matrix3(int **ptrs)
{
    free(ptrs[0]);
    free(ptrs);
}

