#ifndef PROCESSING_H
#define PROCESSING_H

#include "main_header.h"
#include <stdio.h>

#ifdef PR_EXPORTS
#define PR_DLL __declspec(dllexport)
#else
#define PR_DLL __declspec(dllimport)
#endif

#define PR_DECL __cdecl

PR_DLL void PR_DECL mysort(void *first, size_t number, size_t size, int(*comparator)(const void*, const void*));

PR_DLL int PR_DECL key(int *src, int src_len, int *dst, int *dst_len);

void swap(void *a, void *b, size_t size);

#endif // PROCESSING_H
