#include "matrix_operations.h"

void add_matrix(int n, int m, double **ptrs1, double **ptrs2, double **ptrs_res)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ptrs_res[i][j] = ptrs1[i][j] + ptrs2[i][j];
}

void mult_matrix(int n1, int m1, int m2, double **ptrs1, double **ptrs2, double **ptrs_res)
{
    double result;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
        {
            result = 0;
            for (int k = 0; k < m1; k++)
                result += (ptrs1[i][k] * ptrs2[k][j]);
            ptrs_res[i][j] = result;
        }
}

double get_gaus_det(int n, double **ptrs)
{
    double det = 1;
    int lead_i;
    double lead_v;
    double mult = 1;

    for (int it = 0; it < n; it++)
    {
        lead_i = -1;
        lead_v = 0;
        for (int i = it; i < n; i++)
            if ((fabs(ptrs[i][it]) - fabs(lead_v)) > EPS)
            {
                lead_i = i;
                lead_v = ptrs[i][it];
            }
        if (lead_i == -1)
            return 0;
        if (lead_i != it)
        {
            double *temp = ptrs[it];
            ptrs[it] = ptrs[lead_i];
            ptrs[lead_i] = temp;
            det *= -1;
        }

        for (int j = it + 1; j < n; j++)
            if (fabs(ptrs[j][it] - 0) > EPS)
            {
                mult = 1 / ptrs[it][it] * ptrs[j][it];

                for (int k = it; k < n; k++)
                    ptrs[j][k] -= ptrs[it][k] * mult;
            }

        det *= ptrs[it][it];
    }
    return det;
}


