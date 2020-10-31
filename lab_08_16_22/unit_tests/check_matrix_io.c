#include "check_main.h"

START_TEST(test_input_nonexist_file)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;

    rc = input_dm_from_file("unit_tests\\test_input_nonexist_file.txt", &ptrs, &n, &m);
    ck_assert_int_eq(rc, ERROPEN);
    ck_assert_int_eq(n, 0);
    ck_assert_int_eq(m, 0);
    ck_assert_ptr_null(ptrs);
}
END_TEST

START_TEST(test_input_empty_file)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_empty_file.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
        rc = input_dm_from_file("unit_tests\\test_input_empty_file.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_null(ptrs);
	}
}
END_TEST

START_TEST(test_input_incorrect_n)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_incorrect_n.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_incorrect_n.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_null(ptrs);
	}
}
END_TEST

START_TEST(test_input_incorrect_m)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_incorrect_m.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_incorrect_m.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_null(ptrs);
	}
}
END_TEST

START_TEST(test_input_neg_amount)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_neg_amount.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_neg_amount.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_null(ptrs);
	}
}
END_TEST

START_TEST(test_input_toobig_amount)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_toobig_amount.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_toobig_amount.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_null(ptrs);
	}
}
END_TEST

START_TEST(test_input_not_enough_records)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_not_enough_records.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_not_enough_records.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_nonnull(ptrs);
        free_matrix(ptrs);
	}
}
END_TEST

START_TEST(test_input_toomany_records)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_toomany_records.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_toomany_records.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_nonnull(ptrs);
        free_matrix(ptrs);
	}
}
END_TEST

START_TEST(test_input_big_i)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_big_i.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_big_i.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_nonnull(ptrs);
        free_matrix(ptrs);
	}
}
END_TEST

START_TEST(test_input_small_i)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_small_i.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_small_i.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_nonnull(ptrs);
        free_matrix(ptrs);
	}
}
END_TEST

START_TEST(test_input_big_j)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_big_j.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_big_j.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_nonnull(ptrs);
        free_matrix(ptrs);
	}
}
END_TEST

START_TEST(test_input_small_j)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_small_j.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_small_j.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_nonnull(ptrs);
        free_matrix(ptrs);
	}
}
END_TEST


START_TEST(test_input_repeated_records)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_repeated_records.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_repeated_records.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_nonnull(ptrs);
        free_matrix(ptrs);
	}
}
END_TEST

START_TEST(test_input_null_record)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_null_record.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_null_record.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_nonnull(ptrs);
        free_matrix(ptrs);
	}
}
END_TEST

START_TEST(test_input_letter_in_record)
{
    double **ptrs = NULL;
    int n = 0, m = 0;
    int rc;
	
	FILE *f = fopen("unit_tests\\test_input_letter_in_record.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_letter_in_record.txt", &ptrs, &n, &m);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 0);
        ck_assert_int_eq(m, 0);
        ck_assert_ptr_nonnull(ptrs);
        free_matrix(ptrs);
	}
}
END_TEST

START_TEST(test_input_1_elem_zero)
{
    double a[1][1] = {{0}};
    double *ptrs1[1] = {a[0]};
    int n1 = 1, m1 = 1;

    double **ptrs2 = NULL;
    int n2, m2;
    int rc, result;
	
	FILE *f = fopen("unit_tests\\test_input_1_elem_zero.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_1_elem_zero.txt", &ptrs2, &n2, &m2);
        ck_assert_int_eq(rc, OK);
        ck_assert_ptr_nonnull(ptrs2);
    
        result = check_dm_eq(n1, m1, n2, m2, ptrs1, ptrs2);
        ck_assert_int_eq(result, 1);
        free_matrix(ptrs2);
	}
}
END_TEST

START_TEST(test_input_usual)
{
    double a[2][3] = {{1.1, 0, 0}, {1, 2, 0}};
    double *ptrs1[2] = {a[0], a[1]};
    int n1 = 2, m1 = 3;

    double **ptrs2 = NULL;
    int n2, m2;
    int rc, result;
	
	FILE *f = fopen("unit_tests\\test_input_usual.txt", "r");
	if (f != NULL)
	{
    	fclose(f);
    
        rc = input_dm_from_file("unit_tests\\test_input_usual.txt", &ptrs2, &n2, &m2);
        ck_assert_int_eq(rc, OK);
        ck_assert_ptr_nonnull(ptrs2);
    
        result = check_dm_eq(n1, m1, n2, m2, ptrs1, ptrs2);
        ck_assert_int_eq(result, 1);
        free_matrix(ptrs2);
	}
}
END_TEST

Suite* input_dm_from_file_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("input_dm_from_file");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_input_nonexist_file);
    tcase_add_test(tc_neg, test_input_empty_file);
    tcase_add_test(tc_neg, test_input_incorrect_n);
    tcase_add_test(tc_neg, test_input_incorrect_m);
    tcase_add_test(tc_neg, test_input_neg_amount);
    tcase_add_test(tc_neg, test_input_toobig_amount);
    tcase_add_test(tc_neg, test_input_not_enough_records);
    tcase_add_test(tc_neg, test_input_toomany_records);
    tcase_add_test(tc_neg, test_input_big_i);
    tcase_add_test(tc_neg, test_input_small_i);
    tcase_add_test(tc_neg, test_input_big_j);
    tcase_add_test(tc_neg, test_input_small_j);
    tcase_add_test(tc_neg, test_input_repeated_records);
    tcase_add_test(tc_neg, test_input_null_record);
    tcase_add_test(tc_neg, test_input_letter_in_record);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_input_1_elem_zero);
    tcase_add_test(tc_pos, test_input_usual);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_output_no_nonnull)
{
    double a[2][3] = {{0, 0, 0}, {0, 1e-10, 0}};
    double *ptrs1[2] = {a[0], a[1]};
    int n1 = 2, m1 = 3;

    FILE *f = fopen("unit_tests\\test_output_no_nonnull.txt", "w");
    if (f != NULL)
    {
        output_dm_to_file(f, n1, m1, ptrs1);
        fclose(f);
    
        double **ptrs2 = NULL;
        int n2, m2;
        int rc, result;
        rc = input_dm_from_file("unit_tests\\test_output_no_nonnull.txt", &ptrs2, &n2, &m2);
        ck_assert_int_eq(rc, OK);
        ck_assert_ptr_nonnull(ptrs2);
    
        result = check_dm_eq(n1, m1, n2, m2, ptrs1, ptrs2);
        ck_assert_int_eq(result, 1);
    
        free_matrix(ptrs2);
    }
}
END_TEST

START_TEST(test_output_usual)
{
    double a[2][3] = {{1.2, 0, -4}, {0, 1e-10, 0}};
    double *ptrs1[2] = {a[0], a[1]};
    int n1 = 2, m1 = 3;

    FILE *f = fopen("unit_tests\\test_output_usual.txt", "w");
    if (f != NULL)
    {
        output_dm_to_file(f, n1, m1, ptrs1);
        fclose(f);
    
        double **ptrs2 = NULL;
        int n2, m2;
        int rc, result;
        rc = input_dm_from_file("unit_tests\\test_output_usual.txt", &ptrs2, &n2, &m2);
        ck_assert_int_eq(rc, OK);
        ck_assert_ptr_nonnull(ptrs2);
    
        result = check_dm_eq(n1, m1, n2, m2, ptrs1, ptrs2);
        ck_assert_int_eq(result, 1);
    
        free_matrix(ptrs2);
    }
}
END_TEST

Suite* output_dm_to_file_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("output_dm_to_file");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_output_no_nonnull);
    tcase_add_test(tc_neit, test_output_usual);
    suite_add_tcase(s, tc_neit);

    return s;
}
