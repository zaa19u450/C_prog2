#ifndef PROCESSING_H
#define PROCESSING_H

#include "main_header.h"
#include <stdio.h>

void mysort(void *first, size_t number, size_t size, int(*comparator)(const void*, const void*));

int key(int *src, int src_len, int *dst, int *dst_len);

void swap(void *a, void *b, size_t size);

#endif // PROCESSING_H
