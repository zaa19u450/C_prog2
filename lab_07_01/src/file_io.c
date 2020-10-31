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
