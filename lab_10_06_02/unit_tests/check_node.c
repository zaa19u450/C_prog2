#include "check_main.h"

START_TEST(test_node_create_null)
{
    node_t *node1 = NULL;
    node_t node2 = {0, 0, 0, NULL};
    node1 = node_create(0, 0, 0);
    ck_assert_ptr_nonnull(node1);
    ck_assert_int_eq(matrix_eq(node1, &node2), 1);
    node_free(node1);
}
END_TEST

START_TEST(test_node_create_nonnull)
{
    node_t *node1 = NULL;
    node_t node2 = {1, 10, 5, NULL};
    node1 = node_create(1, 10, 5);
    ck_assert_ptr_nonnull(node1);
    ck_assert_int_eq(matrix_eq(node1, &node2), 1);
    node_free(node1);
}
END_TEST

Suite* node_create_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("node_create");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_node_create_null);
    tcase_add_test(tc_neit, test_node_create_nonnull);

    suite_add_tcase(s, tc_neit);

    return s;
}

