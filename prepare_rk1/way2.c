//Матрица как массив указателей
#include <stdlib.h>
#include "main_header.h"

//Выход: указатель на массив строк матрицы (p)
int allocate_matrix2(int ***ptrs, int n, int m)
{
    int **ptrs_tmp = calloc(n, sizeof(int *));
    if (ptrs_tmp == NULL)
        return ERRMEM;
    else
    {
        for (int i = 0; i < n; i++)
        {
            ptrs_tmp[i] = calloc(m, sizeof(int));
            if (ptrs_tmp[i] == NULL)
            {
                free_matrix2(ptrs_tmp, n);
                return ERRMEM;
            }
        }
        *ptrs = ptrs_tmp;
        return OK;
    }
}

void free_matrix2(int **ptrs, int n)
{
    for (int i = 0; i < n; i++)
       free(ptrs[i]);
    free(ptrs);
}

