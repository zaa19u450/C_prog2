#include "read_sort.h"

int read_sort_title(FILE *f, film_struct film_arr[])
{
    int i = 0;
    for (; !feof(f); i++)
    {
        if (i == AMOUNT)
            return TOOMANY;
        else
        {
            if (fgets(film_arr[i].title, TITLELEN + 1, f) != NULL
                 && (fscanf(f, "%*[\n]") || 1)
                 && fgets(film_arr[i].name, NAMELEN + 1, f) != NULL
                 && fscanf(f, "%d\n", &(film_arr[i].year)) == 1
                 && film_arr[i].year > MINYEAR
                 && film_arr[i].year < MAXYEAR)
            {
                if (film_arr[i].title[strlen(film_arr[i].title) - 1] == '\n')
                    film_arr[i].title[strlen(film_arr[i].title) - 1] = '\0';
                if (film_arr[i].name[strlen(film_arr[i].name) - 1] == '\n')
                    film_arr[i].name[strlen(film_arr[i].name) - 1] = '\0';
                for (int j = i; (j > 0) && (strcmp(film_arr[j].title, film_arr[j - 1].title) < 0); j--)
                {
                    film_struct film = film_arr[j];
                    film_arr[j] = film_arr[j - 1];
                    film_arr[j - 1] = film;
                }
            }
            else
                return ERRVALUE;
        }
    }
    if (i > 0)
        return i;
    else
        return ERREMPTY;
}

int read_sort_name(FILE *f, film_struct film_arr[])
{
    int i = 0;
    for (; !feof(f); i++)
    {
        if (i == AMOUNT)
            return TOOMANY;
        else
        {
            if (fgets(film_arr[i].title, TITLELEN + 1, f) != NULL
                 && (fscanf(f, "%*[\n]") || 1)
                 && fgets(film_arr[i].name, NAMELEN + 1, f) != NULL
                 && fscanf(f, "%d\n", &(film_arr[i].year)) == 1
                 && film_arr[i].year > MINYEAR
                 && film_arr[i].year < MAXYEAR)
            {
                if (film_arr[i].title[strlen(film_arr[i].title) - 1] == '\n')
                    film_arr[i].title[strlen(film_arr[i].title) - 1] = '\0';
                if (film_arr[i].name[strlen(film_arr[i].name) - 1] == '\n')
                    film_arr[i].name[strlen(film_arr[i].name) - 1] = '\0';
                for (int j = i; (j > 0) && (strcmp(film_arr[j].name, film_arr[j - 1].name) < 0); j--)
                {
                    film_struct film = film_arr[j];
                    film_arr[j] = film_arr[j - 1];
                    film_arr[j - 1] = film;
                }
            }
            else
                return ERRVALUE;
        }
    }
    if (i > 0)
        return i;
    else
        return ERREMPTY;
}

int read_sort_year(FILE *f, film_struct film_arr[])
{
    int i = 0;
    for (; !feof(f); i++)
    {
        if (i == AMOUNT)
            return TOOMANY;
        else
        {
            if (fgets(film_arr[i].title, TITLELEN + 1, f) != NULL
                 && (fscanf(f, "%*[\n]") || 1)
                 && fgets(film_arr[i].name, NAMELEN + 1, f) != NULL
                 && fscanf(f, "%d\n", &(film_arr[i].year)) == 1
                 && film_arr[i].year > MINYEAR
                 && film_arr[i].year < MAXYEAR)
            {
                if (film_arr[i].title[strlen(film_arr[i].title) - 1] == '\n')
                    film_arr[i].title[strlen(film_arr[i].title) - 1] = '\0';
                if (film_arr[i].name[strlen(film_arr[i].name) - 1] == '\n')
                    film_arr[i].name[strlen(film_arr[i].name) - 1] = '\0';
                for (int j = i; (j > 0) && (film_arr[j].year - film_arr[j - 1].year < 0); j--)
                {
                    film_struct film = film_arr[j];
                    film_arr[j] = film_arr[j - 1];
                    film_arr[j - 1] = film;
                }
            }
            else
                return ERRVALUE;
        }
    }
    if (i > 0)
        return i;
    else
        return ERREMPTY;
}
