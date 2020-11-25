#include "check_main.h"
#include <stdio.h>

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

//snprintf from library breaks
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

//zero-length format string
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

//extra args
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

//extra args
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

//not enough args
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

//breaks because of no '\0'
//START_TEST(test_s_inccorrect_argument)
//{
//    char exp_s[MAXLEN] = { '\0' };
//    char my_s[MAXLEN] = { '\0' };
//    int n = 20;

//    int exp_out = snprintf(exp_s, n, "%s", 10);
//    int my_out = my_snprintf(my_s, n, "%s", 10);

//    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
//}
//END_TEST


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
    tcase_add_test(tc_neit, test_s_notenough_args);


    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_lld_max)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "%lld", INT64_MAX);
    int my_out = my_snprintf(my_s, n, "%lld", INT64_MAX);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_lld_min)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "%lld", INT64_MIN);
    int my_out = my_snprintf(my_s, n, "%lld", INT64_MIN);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_lld_0)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "%lld", 0ll);
    int my_out = my_snprintf(my_s, n, "%lld", 0ll);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_lld_a30300b)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "a%lldb", 30300ll);
    int my_out = my_snprintf(my_s, n, "a%lldb", 30300ll);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_lld_not_enough_space)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 5;

    int exp_out = snprintf(exp_s, n, "%lld", -123456ll);
    int my_out = my_snprintf(my_s, n, "%lld", -123456ll);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST


//not enough args
START_TEST(test_lld_not_enough_args)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "%lld  %lld", 10ll);
    int my_out = my_snprintf(my_s, n, "%lld  %lld", 10ll);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//extra args
START_TEST(test_lld_extra_args)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "%lld", 10ll, 10ll);
    int my_out = my_snprintf(my_s, n, "%lld", 10ll, 10ll);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//wrong type of argument
START_TEST(test_lld_inccorrect_argument)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 20;

    int exp_out = snprintf(exp_s, n, "%lld", "a");
    int my_out = my_snprintf(my_s, n, "%lld", "a");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//integer overflow expression
//START_TEST(test_lld_more_max)
//{
//    char exp_s[MAXLEN] = { '\0' };
//    char my_s[MAXLEN] = { '\0' };
//    int n = 30;

//    int exp_out = snprintf(exp_s, n, "%lld", INT64_MAX + 1);
//    int my_out = my_snprintf(my_s, n, "%lld", INT64_MAX + 1);

//    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
//}
//END_TEST

//integer overflow expression
//START_TEST(test_lld_less_min)
//{
//    char exp_s[MAXLEN] = { '\0' };
//    char my_s[MAXLEN] = { '\0' };
//    int n = 30;

//    int exp_out = snprintf(exp_s, n, "%lld", INT64_MIN - 1);
//    int my_out = my_snprintf(my_s, n, "%lld", INT64_MIN - 1);

//    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
//}
//END_TEST


Suite* lld_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("lld_specificator");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_lld_max);
    tcase_add_test(tc_neit, test_lld_min);
    tcase_add_test(tc_neit, test_lld_0);
    tcase_add_test(tc_neit, test_lld_a30300b);
    tcase_add_test(tc_neit, test_lld_not_enough_space);

    //not allowed
    tcase_add_test(tc_neit, test_lld_not_enough_args);
    tcase_add_test(tc_neit, test_lld_extra_args);
    tcase_add_test(tc_neit, test_lld_inccorrect_argument);


    suite_add_tcase(s, tc_neit);

    return s;
}


START_TEST(test_ho_neg)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "%ho", -100);
    int my_out = my_snprintf(my_s, n, "%ho", -100);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_ho_0)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "%ho", 0);
    int my_out = my_snprintf(my_s, n, "%ho", 0);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_ho_8ord)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "%ho", 512);
    int my_out = my_snprintf(my_s, n, "%ho", 512);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_ho_a_101_0)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "a%ho0", 101);
    int my_out = my_snprintf(my_s, n, "a%ho0", 101);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

START_TEST(test_ho_not_enough_space)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 3;

    int exp_out = snprintf(exp_s, n, "%ho", 5000);
    int my_out = my_snprintf(my_s, n, "%ho", 5000);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//not enough args
START_TEST(test_ho_not_enough_args)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "%ho  %ho", 10);
    int my_out = my_snprintf(my_s, n, "%ho  %ho", 10);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//extra args
START_TEST(test_ho_extra_args)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "%ho", 10, 10);
    int my_out = my_snprintf(my_s, n, "%ho", 10, 10);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//wrong type of argument
START_TEST(test_ho_incorrect_arg)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "%ho", "10, 10");
    int my_out = my_snprintf(my_s, n, "%ho", "10, 10");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//integer overflow expression
//START_TEST(test_ho_overflow)
//{
//    char exp_s[MAXLEN] = { '\0' };
//    char my_s[MAXLEN] = { '\0' };
//    int n = 30;

//    int exp_out = snprintf(exp_s, n, "%ho", INT64_MAX);
//    int my_out = my_snprintf(my_s, n, "%ho", INT64_MAX);

//    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
//}
//END_TEST

Suite* ho_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("ho_specificator");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_ho_neg);
    tcase_add_test(tc_neit, test_ho_0);
    tcase_add_test(tc_neit, test_ho_8ord);
    tcase_add_test(tc_neit, test_ho_a_101_0);
    tcase_add_test(tc_neit, test_ho_not_enough_space);

    //not allowed
    tcase_add_test(tc_neit, test_ho_not_enough_args);
    tcase_add_test(tc_neit, test_ho_extra_args);
    tcase_add_test(tc_neit, test_ho_incorrect_arg);


    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_combo_usual)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "a%ho%lld%lld.%s0%hob%s\n", 10, 0ll, 100ll, "qwe", -64, "ab");
    int my_out = my_snprintf(my_s, n, "a%ho%lld%lld.%s0%hob%s\n", 10, 0ll, 100ll, "qwe", -64, "ab");

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//unknown argument
START_TEST(test_combo_unknown_arg_beg)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 10;

    int exp_out = snprintf(exp_s, n, "%kabc", 5);
    int my_out = my_snprintf(my_s, n, "%kabc", 5);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

//unknown argument
START_TEST(test_combo_unknown_arg_mid)
{
    char exp_s[MAXLEN] = { '\0' };
    char my_s[MAXLEN] = { '\0' };
    int n = 20;

    int exp_out = snprintf(exp_s, n, "%s %! %ho", "abc", 10, 10);
    int my_out = my_snprintf(my_s, n, "%s %! %ho", "abc", 10, 10);

    ck_assert_int_eq(worked_cor(exp_s, my_s, exp_out, my_out), 1);
}
END_TEST

Suite* combo_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("combo");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_combo_usual);

    //not allowed
    tcase_add_test(tc_neit, test_combo_unknown_arg_beg);
    tcase_add_test(tc_neit, test_combo_unknown_arg_mid);


    suite_add_tcase(s, tc_neit);

    return s;
}
