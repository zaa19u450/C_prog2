#include "alloc_free.h"

double **allocate_matrix(int n, int m)
{
    double **ptrs, *data;

    ptrs = calloc(n, sizeof(double*));
    if (ptrs == NULL)
        return NULL;

    data = calloc(n * m, sizeof(double));
    if (!data)
    {
        free(ptrs);
        return NULL;
    }

    for (int i = 0; i < n; i++)
        ptrs[i] = data + i * m;

    return ptrs;
}

void free_matrix(double **ptrs)
{
    free(ptrs[0]);
    free(ptrs);
}

