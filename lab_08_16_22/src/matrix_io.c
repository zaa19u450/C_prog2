#include "matrix_io.h"

int input_dm_from_file(char filename[], double ***ptrs, int *n_return, int *m_return)
{
    int rc = OK;
    int n, m, num_elems;
    int i, j;
    double elem;
    FILE *f = fopen(filename, "r");

    if (f == NULL)
        rc = ERROPEN;
    else
    {
        if ((fscanf(f, "%d%d%d", &n, &m, &num_elems) != 3) ||
            (n <= 0) || (m <= 0) || (num_elems < 0) || (num_elems > n * m))
            rc = ERRVALUE;
        else
        {
            *ptrs = allocate_matrix(n, m);
            if (ptrs == NULL)
                rc = ERRMEM;
            else
            {
                for (int k = 0; k < num_elems; k++)
                {
                    if (fgetc(f) != '\n')
                        rc = ERRVALUE;
                    else if ((fscanf(f, "%d%d%lf", &i, &j, &elem) != 3) ||
                        (i <= 0) || (i > n) || (j <= 0) || (j > m) ||
                        (fabs((*ptrs)[i - 1][j - 1] - 0) > EPS) ||
                        (fabs(elem - 0) < EPS))
                    {
                        rc = ERRVALUE;
                        break;
                    }
                    else
                    {
                        (*ptrs)[i - 1][j - 1] = elem;
                    }
                }
                if (rc == OK)
                {
                    fscanf(f, "%d", &i);
                    if (!feof(f))
                        rc = ERRVALUE;
                }
                if (rc != OK)
                    free_matrix(*ptrs);
            }
        }
        fclose(f);
    }
    if (rc == OK)
    {
        *n_return = n;
        *m_return = m;
    }
    return rc;
}

void output_dm_to_file(FILE *f, int n, int m, double **ptrs)
{
    int num_elems = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (fabs(ptrs[i][j] - 0) > EPS)
                num_elems++;

    fprintf(f, "%d %d %d\n", n, m, num_elems);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (fabs(ptrs[i][j] - 0) > EPS)
                fprintf(f, "%d %d %lf\n", i + 1, j + 1, ptrs[i][j]);
}
