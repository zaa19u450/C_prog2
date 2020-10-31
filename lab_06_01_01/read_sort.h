#ifndef READ_SORT_H
#define READ_SORT_H

#include "main_header.h"
int read_sort_title(FILE *f, film_struct film_arr[]);
int read_sort_name(FILE *f, film_struct film_arr[]);
int read_sort_year(FILE *f, film_struct film_arr[]);

#endif // READ_SORT_H
