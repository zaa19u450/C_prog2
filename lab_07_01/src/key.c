#include "key.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    *pb_dst = NULL;
    if (pb_src >= pe_src)
        return ERRDATAFORKEY;
    int *p_min = (int *)pb_src, *p_max = (int *)pb_src;
    int *pa;
    for (pa = (int *)pb_src; pa < pe_src; pa++)
    {
        if (*pa < *p_min)
            p_min = pa;
        else if (*pa > *p_max)
            p_max = pa;
    }
    if (pa != pe_src)
        return ERRDATAFORKEY;
    if (p_min > p_max)
    {
        pa = p_max;
        p_max = p_min;
        p_min = pa;
    }
    int n = (p_max - p_min) - 1;
    if (n <= 0)
        return ERREMPTYMAS;

    *pb_dst = calloc(n, sizeof(int));
    if (*pb_dst != NULL)
    {
        p_min++;
        *pe_dst = *pb_dst + n;
        for (pa = *pb_dst; pa < *pe_dst; pa++)
        {
            *pa = *p_min;
            p_min++;
        }
    }
    else
        return ERRMEM;
    return OK;
}
