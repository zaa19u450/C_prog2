#include "check_main.h"

START_TEST(test_mysort_int_only_one)
{
    int x[] = { 100 };

    mysort(x, 1, sizeof(int), int_cmp);
    ck_assert_int_eq(x[0], 100);
} END_TEST

int char_cmp(const void *val1, const void *val2)
{
    char *x = (char *) val1;
    char *y = (char *) val2;
    return ((*x) - (*y));
}

START_TEST(test_mysort_char_with_repeats)
{
    char x[5] = "bbaca";

    mysort(x, 5, sizeof(char), char_cmp);
    ck_assert_int_eq(x[0], 'a');
    ck_assert_int_eq(x[1], 'a');
    ck_assert_int_eq(x[2], 'b');
    ck_assert_int_eq(x[3], 'b');
    ck_assert_int_eq(x[4], 'c');
} END_TEST

int str_cmp(const void *val1, const void *val2)
{
    char *x = (char *) val1;
    char *y = (char *) val2;
    return strncmp(x, y, strlen(x));
}

START_TEST(test_mysort_string_already_sorted)
{
    char x[3][3] = { "ab", "cd", "ef" };

    mysort(x, 3, sizeof(char[3]), str_cmp);
    ck_assert_str_eq(x[0], "ab");
    ck_assert_str_eq(x[1], "cd");
    ck_assert_str_eq(x[2], "ef");
} END_TEST

int double_cmp(const void *val1, const void *val2)
{
    double *x = (double *) val1;
    double *y = (double *) val2;
    if ((*x - *y) > EPS)
        return 1;
    else if ((*y - *x) > EPS)
        return -1;
    else
        return 0;
}

START_TEST(test_mysort_double)
{
    double x[4] = { 0.01, 0.01, -0.9, 100 };

    mysort(x, 4, sizeof(double), double_cmp);
    ck_assert_double_eq_tol(x[0], -0.9, EPS);
    ck_assert_double_eq_tol(x[1], 0.01, EPS);
    ck_assert_double_eq_tol(x[2], 0.01, EPS);
    ck_assert_double_eq_tol(x[3], 100, EPS);
} END_TEST
Suite * mysort_suite(void)
{
    Suite * s;
    TCase * tc_neit;

    s = suite_create("mysort");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_mysort_int_only_one);
    tcase_add_test(tc_neit, test_mysort_char_with_repeats);
    tcase_add_test(tc_neit, test_mysort_double);
    tcase_add_test(tc_neit, test_mysort_string_already_sorted);
    suite_add_tcase(s, tc_neit);

    return s;
}

