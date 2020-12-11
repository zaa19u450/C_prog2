#include "check_main.h"

START_TEST(test_take_no_repeats_not_enough)
{
    int a[5] = { 1, 2, -1, 0, 4 };
    int b[6] = { 0 };
    int n = 0;

    take_first_occur(a, 5, b, &n);
    ck_assert_int_eq(n, 5);
    take_first_occur(a, 5, b, &n);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(a[i], b[i]);
    ck_assert_int_eq(b[5], 0);
}
END_TEST

START_TEST(test_take_all_repeated_enough)
{
    int a[5] = { 1, 1, 1, 1, 1 };
    int b[2] = { 0 };
    int n = 2;

    take_first_occur(a, 5, b, &n);
    ck_assert_int_eq(n, 1);
    ck_assert_int_eq(b[0], 1);
    ck_assert_int_eq(b[1], 0);
}
END_TEST

START_TEST(test_take_mixed)
{
    int a[6] = { 1, 3, 1, 1, 3, 2 };
    int b[4] = { 0 };
    int n = 3;

    take_first_occur(a, 6, b, &n);
    ck_assert_int_eq(n, 3);
    ck_assert_int_eq(b[0], 1);
    ck_assert_int_eq(b[1], 3);
    ck_assert_int_eq(b[2], 2);
    ck_assert_int_eq(b[3], 0);
}
END_TEST

Suite* take_first_occur_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("take_first_occur");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_take_no_repeats_not_enough);
    tcase_add_test(tc_neit, test_take_all_repeated_enough);
    tcase_add_test(tc_neit, test_take_mixed);

    suite_add_tcase(s, tc_neit);

    return s;
}
