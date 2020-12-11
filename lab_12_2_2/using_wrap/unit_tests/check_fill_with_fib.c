#include "check_main.h"

START_TEST(test_fill_with_fib_1)
{
    int a[1] = { 0 };
    fill_with_fib(1, a);

    ck_assert_int_eq(a[0], 1);
}
END_TEST

START_TEST(test_fill_with_fib_2)
{
    int a[2] = { 0 };
    fill_with_fib(2, a);

    ck_assert_int_eq(a[0], 1);
    ck_assert_int_eq(a[1], 1);
}
END_TEST

START_TEST(test_fill_with_fib_usual)
{
    int a[10] = { 0 };
    fill_with_fib(8, a);

    ck_assert_int_eq(a[0], 1);
    ck_assert_int_eq(a[1], 1);
    ck_assert_int_eq(a[2], 2);
    ck_assert_int_eq(a[3], 3);
    ck_assert_int_eq(a[4], 5);
    ck_assert_int_eq(a[5], 8);
    ck_assert_int_eq(a[6], 13);
    ck_assert_int_eq(a[7], 21);
    ck_assert_int_eq(a[8], 0);
    ck_assert_int_eq(a[9], 0);
}
END_TEST

Suite* fill_with_fib_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("fill_with_fib");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_fill_with_fib_1);
    tcase_add_test(tc_neit, test_fill_with_fib_2);
    tcase_add_test(tc_neit, test_fill_with_fib_usual);

    suite_add_tcase(s, tc_neit);

    return s;
}
