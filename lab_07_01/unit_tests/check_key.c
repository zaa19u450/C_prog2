#include "check_main.h"

START_TEST(test_key_empty_mass_given)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[] = { 0 };
    pb_src = a;
    pe_src = a;
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERRDATAFORKEY);
    ck_assert_ptr_null(pb_dst);
} END_TEST
START_TEST(test_key_empty_mass_made)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[6] = { 3, 3, 1, 10, 3, 3 };
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERREMPTYMAS);
    ck_assert_ptr_null(pb_dst);
} END_TEST
START_TEST(test_key_all_equal)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[6] = { 3, 3, 3, 3, 3, 3 };
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERREMPTYMAS);
    ck_assert_ptr_null(pb_dst);
} END_TEST
START_TEST(test_key_wrong_ptrs_given)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[6] = { 3, 3, 1, 10, 3, 3 };
    pe_src = a;
    pb_src = &a[6];
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERRDATAFORKEY);
    ck_assert_ptr_null(pb_dst);
} END_TEST
START_TEST(test_key_usual)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[6] = { 1, 2, 3, 4, 10, 3 };
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, OK);
    ck_assert_ptr_nonnull(pb_dst);
    ck_assert_int_eq(*pb_dst, 2);
    ck_assert_int_eq(*(pe_dst - 1), 4);
    ck_assert_int_eq((pe_dst - pb_dst), 3);
    free(pb_dst);
} END_TEST
START_TEST(test_key_only_one_left)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[6] = { 1, 2, 10, 4, 5, 3 };
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, OK);
    ck_assert_ptr_nonnull(pb_dst);
    ck_assert_int_eq(*pb_dst, 2);
    ck_assert_int_eq((pe_dst - pb_dst), 1);
    free(pb_dst);
} END_TEST
START_TEST(test_key_more_than_one_max_min)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[6] = { 1, 1, 2, 3, 4, 4 };
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, OK);
    ck_assert_ptr_nonnull(pb_dst);
    ck_assert_int_eq(*pb_dst, 1);
    ck_assert_int_eq(*(pe_dst - 1), 3);
    ck_assert_int_eq((pe_dst - pb_dst), 3);
    free(pb_dst);
} END_TEST
START_TEST(test_key_max_before_min)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[6] = { -2, 2, -2, -3, -4, -4 };
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, OK);
    ck_assert_ptr_nonnull(pb_dst);
    ck_assert_int_eq(*pb_dst, -2);
    ck_assert_int_eq(*(pe_dst - 1), -3);
    ck_assert_int_eq((pe_dst - pb_dst), 2);
    free(pb_dst);
} END_TEST
Suite * key_suite(void)
{
    Suite * s;
    TCase * tc_neg;
    TCase * tc_pos;

    s = suite_create("key");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_key_empty_mass_given);
    tcase_add_test(tc_neg, test_key_empty_mass_made);
    tcase_add_test(tc_neg, test_key_all_equal);
    tcase_add_test(tc_neg, test_key_wrong_ptrs_given);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_key_usual);
    tcase_add_test(tc_pos, test_key_only_one_left);
    tcase_add_test(tc_pos, test_key_more_than_one_max_min);
    tcase_add_test(tc_pos, test_key_max_before_min);
    suite_add_tcase(s, tc_pos);

    return s;
}

