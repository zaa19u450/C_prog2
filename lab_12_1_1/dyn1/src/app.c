#include "main_header.h"
#include "file_io.h"
#include "int_cmp.h"
#include "processing.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = OK;
    int n = 0;
    FILE *f;

    if ((argc < 3) || (argc > 4) || ((argc == 4) && strcmp(argv[3], "f")))
        rc = ERRARGS;
    else
    {
        f = fopen(argv[1], "r");
        if (f)
        {
            rc = count_amount(f, &n);
            if (rc == OK)
            {
                fclose(f);

                int *pb0, *pe0;
                pb0 = calloc(n, sizeof(int));
                if (pb0 != NULL)
                {
                    pe0 = pb0 + n;
                    f = fopen(argv[1], "r");
                    if (f)
                    {
                        from_file_to_array(f, pb0, pe0);
                        if (argc == 4)
                        {
                            int *pb1 = NULL, *pe1;
                            int n = 0;
                            rc = key(pb0, pe0 - pb0, pb1, &n);
                            if (rc == NOTENOUGH)
                            {
                                pb1 = malloc(n * sizeof(int));
                                if (pb1)
                                {
                                    rc = key(pb0, pe0 - pb0, pb1, &n);
                                    if (rc == OK)
                                    {
                                        pe1 = pb1 + n;
                                        mysort(pb1, n, sizeof(int), int_cmp);
                                        f = fopen(argv[2], "w");
                                        if (f)
                                        {
                                            from_array_to_file(f, pb1, pe1);
                                            fclose(f);
                                        }
                                        else
                                            rc = ERROPEN;
                                        free(pb1);
                                    }
                                }
                                else
                                    rc = ERRMEM;
                            }
                        }
                        else
                        {
                            mysort(pb0, pe0 - pb0, sizeof(int), int_cmp);
                            f = fopen(argv[2], "w");
                            if (f)
                            {
                                from_array_to_file(f, pb0, pe0);
                                fclose(f);
                            }
                            else
                                rc = ERROPEN;
                        }
                    }
                    else
                        rc = ERROPEN;
                    free(pb0);
                }
                else
                    rc = ERRMEM;
            }
        }
        else
            rc = ERROPEN;
    }
    return rc;
}
