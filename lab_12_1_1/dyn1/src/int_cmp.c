#include "int_cmp.h"

int int_cmp(const void *val1, const void *val2)
{
    int *x = (int *) val1;
    int *y = (int *) val2;
    return ((*x) - (*y));
}
