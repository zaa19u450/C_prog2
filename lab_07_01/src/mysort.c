#include "mysort.h"

void mysort(void *first, size_t number, size_t size, int(*comparator)(const void*, const void*))
{
    char *left = (char *)first + size;
    char *right = (char *)first + size * (number - 1);
    char *j;
    char *k = right;
    do
    {
        for (j = left; j <= right; j += size)
            if (comparator(j - size, j) > 0)
            {
                swap(j - size, j, size);
                k = j;
            }
        right = k - size;
        for (j = right; j >= left; j -= size)
            if (comparator(j - size, j) > 0)
            {
                swap(j - size, j, size);
                k = j;
            }
        left = k + size;
    }
    while (left <= right);
}
