#include "processing.h"

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

int key(int *src, int src_len, int *dst, int *dst_len)
{
    //подсчитываем необходимый размер
    int min_i = 0, max_i = 0;
    for (int i = 1; i < src_len; i++)
    {
        if (src[i] < src[min_i])
            min_i = i;
        else if (src[i] > src[max_i])
            max_i = i;
    }
    if (min_i > max_i)
    {
        int tmp = min_i;
        min_i = max_i;
        max_i = tmp;
    }
    int n = max_i - min_i - 1;

    //не хаватает выделенной памяти
    if (n > *dst_len)
    {
        *dst_len = n;
        return NOTENOUGH;
    }
    //получим пустой массив
    if (n <= 0)
        return ERREMPTYMAS;
    //заполняем новый массив
    n = 0;
    for (int i = min_i + 1; i < max_i; i++, n++)
    {
        dst[n] = src[i];
    }

    return OK;
}
