#include "search.h"

int search_year(film_struct film_arr[], int n, int year)
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (year < film_arr[middle].year)
            high = middle - 1;
        else if (year > film_arr[middle].year)
            low = middle + 1;
        else
            return middle;
    }
    return NOTFOUND;
}

int search_name(film_struct film_arr[], int n, char name[])
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (strncmp(name, film_arr[middle].name, NAMELEN) < 0)
            high = middle - 1;
        else if (strncmp(name, film_arr[middle].name, NAMELEN) > 0)
            low = middle + 1;
        else
            return middle;
    }
    return NOTFOUND;
}

int search_title(film_struct film_arr[], int n, char title[])
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (strcmp(title, film_arr[middle].title) < 0)
            high = middle - 1;
        else if (strcmp(title, film_arr[middle].title) > 0)
            low = middle + 1;
        else
            return middle;
    }
    return NOTFOUND;
}
