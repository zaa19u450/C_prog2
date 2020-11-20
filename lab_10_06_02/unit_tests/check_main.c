#include "check_main.h"

int matrix_eq(node_t *head1, node_t *head2)
{
    while (head1 && head2)
    {
        if (((head1->i) != (head2->i)) ||
                ((head1->j) != (head2->j)) ||
                ((head1->value) != (head2->value)))
            return 0;
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 || head2)
        return 0;
    return 1;
}


int main(void)
{
    int no_failed = 0;
    SRunner *sr;

    //node
    sr = srunner_create(node_create_suite());

    //matrix
    srunner_add_suite(sr, matrix_read_suite());
    srunner_add_suite(sr, matrix_insert_end_suite());
    srunner_add_suite(sr, matrix_add_suite());
    srunner_add_suite(sr, matrix_mul_suite());
    srunner_add_suite(sr, matrix_delete_row_with_max_suite());

    srunner_run_all(sr, CK_VERBOSE);
    no_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
