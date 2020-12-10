#include "check_main.h"

START_TEST(test_count_amount_empty_file)
{
    FILE *f = fopen("unit_tests\\test_count_amount_empty_file.txt", "r");
    int n;
    int rc;
    if (f)
    {
        rc = count_amount(f, &n);
        ck_assert_int_eq(rc, ERREMPTYFILE);
        fclose(f);
    }
    else
        printf("Error in file opening\n");
} END_TEST
START_TEST(test_count_amount_inc_v)
{
    FILE *f = fopen("unit_tests\\test_count_amount_incorrect_value_in_file.txt", "r");
    int n;
    int rc;
    if (f)
    {
        rc = count_amount(f, &n);
        ck_assert_int_eq(rc, ERRVALUE);
        fclose(f);
    }
    else
        printf("Error in file opening\n");
} END_TEST
START_TEST(test_count_amount_inc_v_end)
{
    FILE *f = fopen("unit_tests\\test_count_amount_incorrect_value_in_file_end.txt", "r");
    int n;
    int rc;
    if (f)
    {
        rc = count_amount(f, &n);
        ck_assert_int_eq(rc, ERRVALUE);
        fclose(f);
    }
    else
        printf("Error in file opening\n");
} END_TEST
START_TEST(test_count_amount_one_num)
{
    FILE *f = fopen("unit_tests\\test_count_amount_one_number_in_file.txt", "r");
    int n;
    int rc;
    if (f)
	{
	    rc = count_amount(f, &n);
	    ck_assert_int_eq(rc, OK);
	    ck_assert_int_eq(n, 1);
	    fclose(f);
	}
	else
	    printf("Error in file opening\n");
} END_TEST
START_TEST(test_count_amount_ten_num)
{
    FILE *f = fopen("unit_tests\\test_count_amount_ten_numbers_in_file.txt", "r");
    int n;
    int rc;
    
    if (f)
    {
        rc = count_amount(f, &n);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(n, 10);
        fclose(f);
    }
    else
        printf("Error in file opening\n");
} END_TEST
Suite * count_amount_suite(void)
{
    Suite * s;
    TCase * tc_neg;
    TCase * tc_pos;

    s = suite_create("count_amount");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_count_amount_empty_file);
    tcase_add_test(tc_neg, test_count_amount_inc_v);
    tcase_add_test(tc_neg, test_count_amount_inc_v_end);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_count_amount_one_num);
    tcase_add_test(tc_pos, test_count_amount_ten_num);
    suite_add_tcase(s, tc_pos);

    return s;
}
