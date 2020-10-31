#include "main_header.h"
#include "alloc_free.h"
#include "matrix_io.h"
#include "matrix_operations.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = OK;
    double **ptrs1 = NULL;
    double **ptrs2 = NULL;
    double **ptrs_res = NULL;
    double det;
    int n1, m1, n2, m2;
    FILE *fout = NULL;

    if ((argc < 4) || (argc > 5) ||
        (strcmp(argv[1], "a") && strcmp(argv[1], "m") && strcmp(argv[1], "o")))
        rc = ERRPARAM;
    else
    {
        if (((!strcmp(argv[1], "a") || !strcmp(argv[1], "m")) && (argc != 5)) || 
            ((!strcmp(argv[1], "o")) && (argc != 4)))
            rc = ERRPARAM;
    }
    if (rc == OK)
    {
        if (!strcmp(argv[1], "a"))
        {
            rc = input_dm_from_file(argv[2], &ptrs1, &n1, &m1);
            if (rc == OK)
            {
                rc = input_dm_from_file(argv[3], &ptrs2, &n2, &m2);
                if (rc == OK)
                {
                    if ((n1 != n2) || (m1 != m2))
                        rc = ERRSIZES;
                    else
                    {
                        ptrs_res = allocate_matrix(n1, m1);
                        if (ptrs_res != NULL)
                        {
                            fout = fopen(argv[4], "w");
                            if (fout)
                            {
                                add_matrix(n1, m1, ptrs1, ptrs2, ptrs_res);
                                output_dm_to_file(fout, n1, m1, ptrs_res);
                                fclose(fout);
                            }
                            else
                                rc = ERROPEN;
                            free_matrix(ptrs_res);
                        }
                        else
                            rc = ERRMEM;
                    }
                    free_matrix(ptrs2);
                }
                free_matrix(ptrs1);
            }
        }
        if (!strcmp(argv[1], "m"))
        {
            rc = input_dm_from_file(argv[2], &ptrs1, &n1, &m1);
            if (rc == OK)
            {
                rc = input_dm_from_file(argv[3], &ptrs2, &n2, &m2);
                if (rc == OK)
                {
                    if (m1 != n2)
                        rc = ERRSIZES;
                    else
                    {
                        ptrs_res = allocate_matrix(n1, m2);
                        if (ptrs_res != NULL)
                        {
                            fout = fopen(argv[4], "w");
                            if (fout)
                            {
                                mult_matrix(n1, m1, m2, ptrs1, ptrs2, ptrs_res);
                                output_dm_to_file(fout, n1, m2, ptrs_res);
                                fclose(fout);
                            }
                            else
                                rc = ERROPEN;
                            free_matrix(ptrs_res);
                        }
                        else
                            rc = ERRMEM;
                    }
                    free_matrix(ptrs2);
                }
                free_matrix(ptrs1);
            }
        }
        if (!strcmp(argv[1], "o"))
        {
            rc = input_dm_from_file(argv[2], &ptrs1, &n1, &m1);
            if (rc == OK)
            {
                if (n1 == m1)
                {
                    double *ptr_to_del = ptrs1[0];

                    det = get_gaus_det(n1, ptrs1);
                    fout = fopen(argv[3], "w");
                    if (fout)
                    {
                        fprintf(fout, "%lf", det);
                        fclose(fout);
                    }
                    else
                        rc = ERROPEN;

                    ptrs1[0] = ptr_to_del;
                }
                else
                    rc = ERRSIZES;
                free_matrix(ptrs1);
            }
        }
    }
    return rc;
}
