#include "print.h"

void print_structures(film_struct film_arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", film_arr[i].title);
        printf("%s\n", film_arr[i].name);
        printf("%d\n", film_arr[i].year);
    }
}
void print_structure(film_struct film)
{
    printf("%s\n", film.title);
    printf("%s\n", film.name);
    printf("%d\n", film.year);
}
