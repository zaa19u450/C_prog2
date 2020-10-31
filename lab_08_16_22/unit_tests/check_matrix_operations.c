#include "check_main.h"

START_TEST(test_add_matrix_all_zeros)
{
    int result;

    int n1 = 2, m1 = 2;
    double a1[2][2] = {{0, 0}, {0, 0}};
    double *ptrs1[2] = {a1[0], a1[1]};

    double a2[2][2] = {{0, 0}, {0, 0}};
    double *ptrs2[2] = {a2[0], a2[1]};

    int n3 = 2, m3 = 2;
    double a3[2][2] = {{0, 0}, {0, 0}};
    double *ptrs3[2] = {a3[0], a3[1]};

    int n_res = 2, m_res = 2;
    double **ptrs_res = NULL;
    ptrs_res = allocate_matrix(n_res, m_res);
    assert(ptrs_res != NULL);
    add_matrix(n1, m1, ptrs1, ptrs2, ptrs_res);

    result = check_dm_eq(n3, m3, n_res, m_res, ptrs3, ptrs_res);
    ck_assert_int_eq(result, 1);
    free_matrix(ptrs_res);
}
END_TEST

START_TEST(test_add_matrix_usual)
{
    int result;

    int n1 = 2, m1 = 3;
    double a1[2][3] = {{-1, 1, 0.01}, {-2, 1.6, 0}};
    double *ptrs1[2] = {a1[0], a1[1]};

    double a2[2][3] = {{1, 1, -0.01}, {-3, -0.1, -10}};
    double *ptrs2[2] = {a2[0], a2[1]};

    int n3 = 2, m3 = 3;
    double a3[2][3] = {{0, 2, 0}, {-5, 1.5, -10}};
    double *ptrs3[2] = {a3[0], a3[1]};

    int n_res = 2, m_res = 3;
    double **ptrs_res = NULL;
    ptrs_res = allocate_matrix(n_res, m_res);
    assert(ptrs_res != NULL);
    add_matrix(n1, m1, ptrs1, ptrs2, ptrs_res);

    result = check_dm_eq(n3, m3, n_res, m_res, ptrs3, ptrs_res);
    ck_assert_int_eq(result, 1);
    free_matrix(ptrs_res);
}
END_TEST

Suite* add_matrix_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("add_matrix");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_add_matrix_all_zeros);
    tcase_add_test(tc_neit, test_add_matrix_usual);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_mult_matrix_id_matrix)
{
    int result;

    int n1 = 2, m1 = 2;
    double a1[2][2] = {{1, 1.1}, {2, 0}};
    double *ptrs1[2] = {a1[0], a1[1]};

    double a2[2][2] = {{1, 0}, {0, 1}};
    double *ptrs2[2] = {a2[0], a2[1]};

    int n3 = 2, m3 = 2;
    double a3[2][2] = {{1, 1.1}, {2, 0}};
    double *ptrs3[2] = {a3[0], a3[1]};

    int n_res = 2, m_res = 2;
    double **ptrs_res = NULL;
    ptrs_res = allocate_matrix(n_res, m_res);
    assert(ptrs_res != NULL);
    mult_matrix(n1, m1, m1, ptrs1, ptrs2, ptrs_res);

    result = check_dm_eq(n3, m3, n_res, m_res, ptrs3, ptrs_res);
    ck_assert_int_eq(result, 1);
    free_matrix(ptrs_res);
}
END_TEST

START_TEST(test_mult_matrix_dif_sizes)
{
    int result;

    int n1 = 2, m1 = 3;
    double a1[2][3] = {{-1, 1, 0.01},
                       {-2, 1.6, 0}};
    double *ptrs1[2] = {a1[0], a1[1]};

    int m2 = 2;
    double a2[3][2] = {{1, -1},
                       {1, -1},
                       {1, -1}};
    double *ptrs2[3] = {a2[0], a2[1], a2[2]};

    int n3 = 2, m3 = 2;
    double a3[2][2] = {{0.01, -0.01}, {-0.4, 0.4}};
    double *ptrs3[2] = {a3[0], a3[1]};

    int n_res = n1, m_res = m2;
    double **ptrs_res = NULL;
    ptrs_res = allocate_matrix(n_res, m_res);
    assert(ptrs_res != NULL);
    mult_matrix(n1, m1, m2, ptrs1, ptrs2, ptrs_res);

    result = check_dm_eq(n3, m3, n_res, m_res, ptrs3, ptrs_res);
    ck_assert_int_eq(result, 1);
    free_matrix(ptrs_res);
}
END_TEST

Suite* mult_matrix_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("mult_matrix");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_mult_matrix_id_matrix);
    tcase_add_test(tc_neit, test_mult_matrix_dif_sizes);
    suite_add_tcase(s, tc_neit);

    return s;
}


START_TEST(test_get_gaus_det_degenerate_simple)
{
    double result;

    int n = 2;
    double a[2][2] = {{0, 1}, {0, 1}};
    double *ptrs[2] = {a[0], a[1]};

    result = get_gaus_det(n, ptrs);

    ck_assert_double_eq_tol(result, 0, EPS);
}
END_TEST

START_TEST(test_get_gaus_det_degenerate_count)
{
    double result;

    int n = 2;
    double a[2][2] = {{1, 2}, {1, 2}};
    double *ptrs[2] = {a[0], a[1]};

    result = get_gaus_det(n, ptrs);

    ck_assert_double_eq_tol(result, 0, EPS);
}
END_TEST

START_TEST(test_get_gaus_det_with_swap)
{
    double result;

    int n = 2;
    double a[2][2] = {{1, 1}, {2, 2}};
    double *ptrs[2] = {a[0], a[1]};

    result = get_gaus_det(n, ptrs);

    ck_assert_double_eq_tol(result, 0, EPS);
}
END_TEST


START_TEST(test_get_gaus_det_usual)
{
    double result;

    int n = 3;
    double a[3][3] = {{-1, 2, 3},
                      {2, 3, 4},
                      {3, 4, 5}};
    double *ptrs[3] = {a[0], a[1], a[2]};

    result = get_gaus_det(n, ptrs);

    ck_assert_double_eq_tol(result, 2, EPS);
}
END_TEST

Suite* get_gaus_det_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("get_gaus_det");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_get_gaus_det_degenerate_simple);
    tcase_add_test(tc_neit, test_get_gaus_det_degenerate_count);
    tcase_add_test(tc_neit, test_get_gaus_det_with_swap);
    tcase_add_test(tc_neit, test_get_gaus_det_usual);
    suite_add_tcase(s, tc_neit);

    return s;
}

