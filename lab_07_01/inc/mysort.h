#ifndef MYSORT_H
#define MYSORT_H

#include "main_header.h"
#include "swap.h"

void mysort(void *first, size_t number, size_t size, int(*comparator)(const void*, const void*));

#endif // MYSORT_H
