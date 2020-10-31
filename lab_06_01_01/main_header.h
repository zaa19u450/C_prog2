#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AMOUNT 15
#define TITLELEN 25
#define NAMELEN 25
#define MINYEAR 0
#define MAXYEAR 2100

#define OK 0
#define ERRPARAM -1
#define ERROPEN -2
#define ERREMPTY -3
#define ERRVALUE -4
#define TOOMANY -5
#define NOTFOUND -6

typedef struct
{
    char title[TITLELEN + 1];
    char name[NAMELEN + 1];
    int year;
} film_struct;

#endif // MAIN_HEADER_H
