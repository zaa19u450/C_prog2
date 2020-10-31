#include "check_main.h"

int main(void)
{
    int no_failed = 0;
    SRunner *sr;
    sr = srunner_create(allocate_matrix_suite());
    srunner_add_suite(sr, input_dm_from_file_suite());
    srunner_add_suite(sr, output_dm_to_file_suite());
    srunner_add_suite(sr, add_matrix_suite());
    srunner_add_suite(sr, mult_matrix_suite());
    srunner_add_suite(sr, get_gaus_det_suite());

    srunner_run_all(sr, CK_VERBOSE);
    no_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
