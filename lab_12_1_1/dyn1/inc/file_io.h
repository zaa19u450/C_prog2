#ifndef FILE_IO_H
#define FILE_IO_H

#include "main_header.h"
#include <stdio.h>

#ifdef IO_EXPORTS
#define IO_DLL __declspec(dllexport)
#else
#define IO_DLL __declspec(dllimport)
#endif

#define IO_DECL __cdecl

IO_DLL int IO_DECL count_amount(FILE *f, int *n);

IO_DLL void IO_DECL from_file_to_array(FILE *f, const int *pb, const int *pe);

IO_DLL void IO_DECL from_array_to_file(FILE *f, const int *pb, const int *pe);

#endif // FILE_IO_H
