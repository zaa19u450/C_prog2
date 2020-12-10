#include "file_io.h"

void from_file_to_array(FILE *f, const int *pb, const int *pe)
{
    for (int *pa = (int *)pb; pa < pe; pa++)
        fscanf(f, "%d", pa);
}

void from_array_to_file(FILE *f, const int *pb, const int *pe)
{
    for (int *pa = (int *)pb; pa < pe; pa++)
        fprintf(f, "%d ", *pa);
}

int count_amount(FILE *f, int *n)
{
    int x;
    while (1)
    {
        if (fscanf(f, "%d", &x) == 1)
            (*n)++;
        else
        {
            if (feof(f))
            {
                if ((*n) > 0)
                    return OK;
                else
                    return ERREMPTYFILE;
            }
            else
                return ERRVALUE;
        }
    }
    return OK;
}
