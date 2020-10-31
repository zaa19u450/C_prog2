#include "check_main.h"

int check_dm_eq(int n1, int m1, int n2, int m2, double **ptrs1, double **ptrs2)
{
    if ((n1 != n2) || (m1 != m2))
        return 0;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++)
            if (fabs(ptrs1[i][j] - ptrs2[i][j]) > EPS)
                return 0;
    return 1;
}

START_TEST(test_allocate_matrix_zeros)
{
    int result;
    int n = 2, m = 2;
    double a[2][2] = {{0, 0}, {0, 0}};
    double *ptrs1[2] = {a[0], a[1]};
    double **ptrs2 = NULL;

    ptrs2 = allocate_matrix(n, m);
    assert(ptrs2 != NULL);
    result = check_dm_eq(n, m, n, m, ptrs1, ptrs2);
    ck_assert_int_eq(result, 1);
    free_matrix(ptrs2);
}
END_TEST

Suite* allocate_matrix_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("allocate_matrix");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_allocate_matrix_zeros);
    suite_add_tcase(s, tc_neit);

    return s;
}
