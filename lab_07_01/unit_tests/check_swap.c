#include "check_main.h"

START_TEST(test_swap_int)
{
    int x = 10;
    int y = -10;

    swap(&x, &y, sizeof(int));
    ck_assert_int_eq(x, -10);
    ck_assert_int_eq(y, 10);
} END_TEST
START_TEST(test_swap_char)
{
    char x = 'a';
    char y = 'b';

    swap(&x, &y, sizeof(char));
    ck_assert_int_eq(x, 'b');
    ck_assert_int_eq(y, 'a');
} END_TEST
START_TEST(test_swap_string)
{
    char x[4] = "abc";
    char y[4] = "ab";

    swap(&x, &y, sizeof(char[4]));
    ck_assert_str_eq(x, "ab\0");
    ck_assert_str_eq(y, "abc");
} END_TEST
START_TEST(test_swap_double)
{
    double x = 1e+1;
    double y = 3e-5;

    swap(&x, &y, sizeof(double));
    ck_assert_double_eq_tol(x, 3e-5, EPS);
    ck_assert_double_eq_tol(y, 1e+1, EPS);
} END_TEST
START_TEST(test_swap_struct)
{
    struct
    {
        int integer;
        char symb;
    } x, y;

    x.integer = 1;
    x.symb = 'a';
    y.integer = 2;
    y.symb = 'b';

    swap(&x, &y, sizeof(x));
    ck_assert_int_eq(x.integer, 2);
    ck_assert_int_eq(y.integer, 1);
    ck_assert_int_eq(x.symb, 'b');
    ck_assert_int_eq(y.symb, 'a');
} END_TEST
Suite * swap_suite(void)
{
    Suite * s;
    TCase * tc_neit;

    s = suite_create("swap");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_swap_int);
    tcase_add_test(tc_neit, test_swap_char);
    tcase_add_test(tc_neit, test_swap_double);
    tcase_add_test(tc_neit, test_swap_string);
    tcase_add_test(tc_neit, test_swap_struct);
    suite_add_tcase(s, tc_neit);

    return s;
}
