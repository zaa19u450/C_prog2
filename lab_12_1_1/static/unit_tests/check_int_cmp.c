#include "check_main.h"

START_TEST(test_int_cmp_equal)
{
    int x = 10;
    int y = 10;
    int result;

    result = int_cmp(&x, &y);
    ck_assert_int_eq(result, 0);
} END_TEST
START_TEST(test_int_cmp_with_positives)
{
    int x = 10;
    int y = 5;
    int result;

    result = int_cmp(&x, &y);
    ck_assert_int_eq(result, 5);
} END_TEST
START_TEST(test_int_cmp_with_negatives)
{
    int x = -20;
    int y = -5;
    int result;

    result = int_cmp(&x, &y);
    ck_assert_int_eq(result, -15);
} END_TEST
START_TEST(test_int_cmp_with_pos_n_neg)
{
    int x = -5;
    int y = 5;
    int result;

    result = int_cmp(&x, &y);
    ck_assert_int_eq(result, -10);
} END_TEST
START_TEST(test_int_cmp_with_zero)
{
    int x = 0;
    int y = -10;
    int result;

    result = int_cmp(&x, &y);
    ck_assert_int_eq(result, 10);
} END_TEST
Suite* int_cmp_suite(void)
{
    Suite * s;
    TCase * tc_neit;

    s = suite_create("int_cmp");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_int_cmp_equal);
    tcase_add_test(tc_neit, test_int_cmp_with_positives);
    tcase_add_test(tc_neit, test_int_cmp_with_negatives);
    tcase_add_test(tc_neit, test_int_cmp_with_pos_n_neg);
    tcase_add_test(tc_neit, test_int_cmp_with_zero);
    suite_add_tcase(s, tc_neit);

    return s;
}

