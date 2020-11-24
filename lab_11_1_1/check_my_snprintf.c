#include "check_main.h"
#include <stdio.h>

//checks without specificators

START_TEST(test_nosp_snull_nnull)
{
    char *exp_s = NULL;
    char *my_s = NULL;
    int n = 0;

    int exp_out = snprintf(exp_s, n, "123");
    int my_out = my_snprintf(my_s, n, "123");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//breaks
//START_TEST(test_nosp_snull_nnonnull)
//{
//    char *exp_s = NULL;
//    char *my_s = NULL;
//    int n = 10;

//    printf("here\n");
//    int exp_out = snprintf(exp_s, n, "123");
//    printf("here\n");
//    int my_out = my_snprintf(my_s, n, "123");
//    printf("here\n");

//    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
//}
//END_TEST

START_TEST(test_nosp_snonnull_nnull)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 0;

    int exp_out = snprintf(exp_s, n, "123");
    int my_out = my_snprintf(my_s, n, "123");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//not allowed
START_TEST(test_nosp_nothing_inputed)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 5;

    int exp_out = snprintf(exp_s, n, "");
    int my_out = my_snprintf(my_s, n, "");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//not allowed
START_TEST(test_nosp_extra_args)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 5;

    int exp_out = snprintf(exp_s, n, "abc", 5);
    int my_out = my_snprintf(my_s, n, "abc", 5);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST



START_TEST(test_nosp_only_zero)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 1;

    int exp_out = snprintf(exp_s, n, "12345");
    int my_out = my_snprintf(my_s, n, "12345");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_nosp_n_less_inputed)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 3;

    int exp_out = snprintf(exp_s, n, "12345");
    int my_out = my_snprintf(my_s, n, "12345");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_nosp_n_more_inputed)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 10;

    int exp_out = snprintf(exp_s, n, "0");
    int my_out = my_snprintf(my_s, n, "0");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_nosp_n_equal_inputed_plus1)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 6;

    int exp_out = snprintf(exp_s, n, "a.b.c");
    int my_out = my_snprintf(my_s, n, "a.b.c");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

Suite* nosp_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("no_specificators");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_nosp_snull_nnull);

    tcase_add_test(tc_neit, test_nosp_snonnull_nnull);
    tcase_add_test(tc_neit, test_nosp_n_less_inputed);
    tcase_add_test(tc_neit, test_nosp_n_more_inputed);
    tcase_add_test(tc_neit, test_nosp_n_equal_inputed_plus1);
    tcase_add_test(tc_neit, test_nosp_only_zero);

    //not allowed
    tcase_add_test(tc_neit, test_nosp_nothing_inputed);
    tcase_add_test(tc_neit, test_nosp_extra_args);

    //breaks
    //tcase_add_test(tc_neit, test_nosp_snull_nnonnull);

    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_s_nothing)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 10;

    int exp_out = snprintf(exp_s, n, "%s", "");
    int my_out = my_snprintf(my_s, n, "%s", "");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_s_before_after)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 20;

    int exp_out = snprintf(exp_s, n, "before%safter", "abc");
    int my_out = my_snprintf(my_s, n, "before%safter", "abc");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_s_wont_begin)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 5;

    int exp_out = snprintf(exp_s, n, "abcd%safter", "abc");
    int my_out = my_snprintf(my_s, n, "abcd%safter", "abc");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_s_wont_end)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 7;

    int exp_out = snprintf(exp_s, n, "abcd%safter", "abcd");
    int my_out = my_snprintf(my_s, n, "abcd%safter", "abcd");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_s_exactly)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 7;

    int exp_out = snprintf(exp_s, n, "abcd%safter", "ab");
    int my_out = my_snprintf(my_s, n, "abcd%safter", "ab");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_s_extra_args)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 20;

    int exp_out = snprintf(exp_s, n, "abcd%safter", "ab", "cd");
    int my_out = my_snprintf(my_s, n, "abcd%safter", "ab", "cd");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//breaks without print
START_TEST(test_s_no_args)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 20;

    printf(".....for no args lib....\n");
    int exp_out = snprintf(exp_s, n, "%s");
    printf(".....for no args my....\n");
    int my_out = my_snprintf(my_s, n, "%s");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_s_notenough_args)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 20;

    int exp_out = snprintf(exp_s, n, "%s%s", "ab");
    int my_out = my_snprintf(my_s, n, "%s%s", "ab");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_s_combination)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 15;

    int exp_out = snprintf(exp_s, n, "%s %s0%s.", "ab","cd","134567890");
    int my_out = my_snprintf(my_s, n, "%s %s0%s.", "ab","cd","134567890");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

Suite* s_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("s_specificator");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_s_nothing);
    tcase_add_test(tc_neit, test_s_before_after);
    tcase_add_test(tc_neit, test_s_wont_begin);
    tcase_add_test(tc_neit, test_s_wont_end);
    tcase_add_test(tc_neit, test_s_exactly);
    tcase_add_test(tc_neit, test_s_combination);

    //not allowed
    tcase_add_test(tc_neit, test_s_extra_args);
    //breaks without print
    tcase_add_test(tc_neit, test_s_no_args);
    tcase_add_test(tc_neit, test_s_notenough_args);


    suite_add_tcase(s, tc_neit);

    return s;
}




START_TEST(test_nosp_unknown_argument)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 6;

    int exp_out = snprintf(exp_s, n, "%k", 5);
    int my_out = my_snprintf(my_s, n, "%k", 5);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST
