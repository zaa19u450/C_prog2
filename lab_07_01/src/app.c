#include "main_header.h"
#include "file_io.h"
#include "key.h"
#include "mysort.h"
#include "count_amount.h"
#include "int_cmp.h"
#include "swap.h"

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
                            int *pb1, *pe1;
                            rc = key(pb0, pe0, &pb1, &pe1);
                            if (rc == OK)
                            {
                                mysort(pb1, pe1 - pb1, sizeof(int), int_cmp);
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
