#include "main_header.h"
#include "read_sort.h"
#include "print.h"
#include "search.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = OK, n;
    FILE *f;

    if ((argc < 3) || (argc > 4) || (strcmp(argv[2], "title") && strcmp(argv[2], "year")
                       && strcmp(argv[2], "name")))
        rc = ERRPARAM;
    else
    {
        f = fopen(argv[1], "r");
        if (f)
        {
            film_struct film_arr[AMOUNT];
            memset(&film_arr, 0, sizeof(film_struct));
            if (!strcmp(argv[2], "title"))
                n = read_sort_title(f, film_arr);
            else
            {
                if (!strcmp(argv[2], "name"))
                    n = read_sort_name(f, film_arr);
                else
                    n = read_sort_year(f, film_arr);
            }
            if (n > 0)
            {
                if (argc == 3)
                    print_structures(film_arr,  n);
                else
                {
                    int k = ERRPARAM;
                    if (!strcmp(argv[2], "year") && atoi(argv[3]) && (atoi(argv[3]) > MINYEAR) && (atoi(argv[3]) < MAXYEAR))
                        k = search_year(film_arr, n, atoi(argv[3]));
                    if (!strcmp(argv[2], "name") && (strlen(argv[3]) <= NAMELEN))
                        k = search_name(film_arr, n, argv[3]);
                    if (!strcmp(argv[2], "title") && (strlen(argv[3]) <= TITLELEN))
                        k = search_title(film_arr, n, argv[3]);
                    if (k >= 0)
                        print_structure(film_arr[k]);
                    else
                    {
                        if (k == NOTFOUND)
                            printf("Not found");
                        else
                            rc = k;
                    }
                }
            }
            else
                rc = n;
        fclose(f);
        }
        else
            rc = ERROPEN;
    }
    return rc;
}
