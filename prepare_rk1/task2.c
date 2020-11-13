#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERRMEM -1
#define ERRINPUT -2


int allocate_matrix(int ***ptrs, int n, int m)
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

void free_matrix(int **ptrs)
{
    free(ptrs[0]);
    free(ptrs);
}

int input_matrix(FILE *f, int ***ptrs, int *n, int *m)
{
    int rc = OK;
    int n_tmp, m_tmp;
    int **ptrs_tmp = NULL;

    if ((fscanf(f, "%d", &n_tmp) == 1) && (fscanf(f, "%d", &m_tmp) == 1))
    {
        rc = allocate_matrix(&ptrs_tmp, n_tmp, m_tmp);
        if (rc == OK)
        {
            for (int i = 0; (i < n_tmp) && (rc == OK); i++)
                for (int j = 0; (j < m_tmp) && (rc == OK); j++)
                    if (fscanf(f, "%d", &ptrs_tmp[i][j]) != 1)
                        rc = ERRINPUT;
            if (rc == OK)
            {
                *n = n_tmp;
                *m = m_tmp;
                *ptrs = ptrs_tmp;
            }
            else
                free_matrix(ptrs_tmp);
        }
    }
    else
        rc = ERRINPUT;
    return rc;
}

void print_matrix(FILE *f, int **ptrs, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            fprintf(f, "%d ", ptrs[i][j]);
        fprintf(f, "\n");
    }
}

int find_minsum_str(int **ptrs, int n, int m)
{
    int min_sum = 0;
    int i_min = 0;
    for (int j = 0; j < m; j++)
        min_sum += ptrs[0][j];

    int tek_sum = 0;
    for (int i = 1; i < n; i++)
    {
        tek_sum = 0;
        for (int j = 0; j < m; j++)
            tek_sum += ptrs[i][j];
        if (tek_sum < min_sum)
        {
            min_sum = tek_sum;
            i_min = i;
        }
    }
    return i_min;
}

int find_maxsum_stlb(int **ptrs, int n, int m)
{
    int max_sum = 0;
    int j_max = 0;
    for (int i = 0; i < n; i++)
        max_sum += ptrs[i][0];

    int tek_sum = 0;
    for (int j = 1; j < m; j++)
    {
        tek_sum = 0;
        for (int i = 0; i < n; i++)
            tek_sum += ptrs[i][j];
        if (tek_sum > max_sum)
        {
            max_sum = tek_sum;
            j_max = j;
        }
    }
    return j_max;
}

void delete_minsum_str(int **ptrs, int n, int str)
{
    for (int i = str; i < n - 1; i++)
        ptrs[i] = ptrs[i + 1];
}

void delete_maxsum_stlb(int **ptrs, int n, int m, int stlb)
{
    for (int i = 0; i < n; i++)
        for (int j = stlb; j < m - 1; j++)
            ptrs[i][j] = ptrs[i][j + 1];
}

int main(void)
{
    setbuf(stdout, NULL);
    int rc = OK;
    int **ptrs = NULL;
    int n = 0, m = 0;
    int *ptr0 = NULL;
    int i_min = 0;
    int j_max = 0;

    rc = input_matrix(stdin, &ptrs, &n, &m);
    if (rc == OK)
    {
        fprintf(stdout, "Got matrix:\n");
        print_matrix(stdout, ptrs, n, m);
        //minstr
        i_min = find_minsum_str(ptrs, n, m);
        fprintf(stdout, "Min i %d:\n", i_min);
        ptr0 = ptrs[0];
        delete_minsum_str(ptrs, n, i_min);
        n = n - 1;
        fprintf(stdout, "Result matrix:\n");
        print_matrix(stdout, ptrs, n, m);

        //maxstl
        j_max = find_maxsum_stlb(ptrs, n, m);
        fprintf(stdout, "Max j %d:\n", j_max);
        delete_maxsum_stlb(ptrs, n, m, j_max);
        m = m - 1;
        fprintf(stdout, "Result matrix:\n");
        print_matrix(stdout, ptrs, n, m);

        ptrs[0] = ptr0;
        free_matrix(ptrs);

        //transpose
    }
    return rc;
}
