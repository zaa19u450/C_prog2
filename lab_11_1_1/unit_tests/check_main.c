#include "check_main.h"
#include <stdlib.h>
#include <stdio.h>

int worked_cor(char *exp_s, char *my_s, int exp_out, int my_out)
{
    if ((exp_s == NULL) && (my_s == NULL) && (exp_out == my_out))
        return 1;
    if (strcmp(exp_s, my_s) || (exp_out != my_out))
        return 0;
    else
        return 1;
}

int main(void)
{
    int no_failed = 0;
    SRunner *sr;

    sr = srunner_create(nosp_suite());
    srunner_add_suite(sr, s_suite());
    srunner_add_suite(sr, lld_suite());
    srunner_add_suite(sr, ho_suite());
    srunner_add_suite(sr, combo_suite());

    srunner_run_all(sr, CK_VERBOSE);
    no_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
