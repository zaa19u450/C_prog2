#include "main_header.h"
#include <stdio.h>

int main(void)
{
    int *matrix = NULL;
    int **ptrs = NULL;
    int n = 10, m = 5;
    int rc = OK;

    rc = allocate_matrix1(&matrix, n, m);
    if (rc == OK)
    {
        printf("Way1\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%d ", matrix[m * i + j]);
            printf("\n");
        }
        printf("\n\n");
        free_matrix1(matrix);
    }
    else
        return ERRMEM;

    rc = allocate_matrix2(&ptrs, n, m);
    if (rc == OK)
    {
        printf("Way2\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%d ", ptrs[i][j]);
            printf("\n");
        }
        printf("\n\n");
        free_matrix2(ptrs, n);
    }
    else
        return ERRMEM;

    rc = allocate_matrix3(&ptrs, n, m);
    if (rc == OK)
    {
        printf("Way3\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%d ", ptrs[i][j]);
            printf("\n");
        }
        printf("\n\n");
        free_matrix3(ptrs);
    }
    else
        return ERRMEM;

    rc = allocate_matrix4(&ptrs, n, m);
    if (rc == OK)
    {
        printf("Way4\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                *(((char *) ptrs) + n * sizeof(int *) + i * m + j) = i * m + j;
                printf("%d ", *(((char *) ptrs) + n * sizeof(int *) + i * m + j));
            }
            printf("\n");
        }
        printf("\n\n");
        free_matrix4(ptrs);
    }
    else
        return ERRMEM;

}
