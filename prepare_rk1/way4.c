//Объединение подходов (2) - как (1) только одним блоком
#include <stdlib.h>
#include "main_header.h"

int allocate_matrix4(int ***ptrs, int n, int m)
{
    int **ptrs_tmp = malloc(n * sizeof(int *) +
                              n * m * sizeof(int));
    if (ptrs_tmp == NULL)
        return ERRMEM;

    for (int i = 0; i < n; i++)
        ptrs_tmp[i] = (int *)((char *) ptrs_tmp +
                          n * sizeof(int *) +
                                  i * m * sizeof(int));
    *ptrs = ptrs_tmp;
    return OK;
}

void free_matrix4(int **ptrs)
{
    free(ptrs);
}



