#include "swap.h"

void swap(void *a, void *b, size_t size)
{
    char *aa = a, *bb = b;
    do
    {
        char tmp = *aa;
        *aa++ = *bb;
        *bb++ = tmp;
    } while (--size > 0);
}
