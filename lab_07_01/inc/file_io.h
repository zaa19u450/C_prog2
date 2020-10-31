#ifndef FILE_IO_H
#define FILE_IO_H

#include "main_header.h"

void from_file_to_array(FILE *f, const int *pb, const int *pe);
void from_array_to_file(FILE *f, const int *pb, const int *pe);

#endif // FILE_IO_H
