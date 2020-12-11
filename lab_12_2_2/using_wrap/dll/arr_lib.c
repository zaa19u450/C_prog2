#include "arr_lib.h"
#include <assert.h>
#include <stdio.h>

ARR_DLL void ARR_DECL fill_with_fib(int n, int *arr)
{
    arr[0] = 1;
    if (n > 1)
    {
        arr[1] = 1;
        for (int i = 2; i < n; i++)
            arr[i] = arr[i - 1] + arr[i - 2];
    }   
}

int met_before(int *arr, int i)
{
    for (int j = 0; j < i; j++)
        if (arr[j] == arr[i])
            return 1;
    return 0;
}

ARR_DLL void ARR_DECL take_first_occur(int *src, int src_len, int *dst, int *dst_len)
{
    int n = 0;
    //подсчитываем необходимый размер
    for (int i = 0; i < src_len; i++)
        if (!met_before(src, i))
        {
            n++;
        }

    //не хаватает выделенной памяти
    if (n > *dst_len)
    {
        *dst_len = n;
        return;
    }
    *dst_len = n;
    //заполняем новый массив
    n = 0;
    for (int i = 0; i < src_len; i++)
    {
        if (!met_before(src, i))
        {
            dst[n++] = src[i];
        }
    }
}
