#include "count_amount.h"

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
