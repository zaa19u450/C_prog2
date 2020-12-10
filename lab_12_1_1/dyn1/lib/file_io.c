#include "file_io.h"

IO_DLL void IO_DECL from_file_to_array(FILE *f, const int *pb, const int *pe)
{
    for (int *pa = (int *)pb; pa < pe; pa++)
        fscanf(f, "%d", pa);
}

IO_DLL void IO_DECL from_array_to_file(FILE *f, const int *pb, const int *pe)
{
    for (int *pa = (int *)pb; pa < pe; pa++)
        fprintf(f, "%d ", *pa);
}

IO_DLL int IO_DECL count_amount(FILE *f, int *n)
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
