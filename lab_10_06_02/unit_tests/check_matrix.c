#include "check_main.h"

START_TEST(test_matrix_read_empty_file)
{
    FILE *f = fopen("unit_tests/test_matrix_read_empty_file.txt", "r");
    if (f)
    {
        node_t *head1 =matrix_read(f);
        ck_assert_ptr_null(head1);
    }
    else
        printf("Couldn't check1!\n");
}
END_TEST

START_TEST(test_matrix_read_not_enough)
{
    FILE *f = fopen("unit_tests/test_matrix_read_not_enough.txt", "r");
    if (f)
    {
        node_t *head1 =matrix_read(f);
        ck_assert_ptr_null(head1);
    }
    else
        printf("Couldn't check2!\n");
}
END_TEST

START_TEST(test_matrix_read_incorrect_n_0)
{
    FILE *f = fopen("unit_tests/test_matrix_read_incorrect_n_0.txt", "r");
    if (f)
    {
        node_t *head1 =matrix_read(f);
        ck_assert_ptr_null(head1);
    }
    else
        printf("Couldn't check3!\n");
}
END_TEST

START_TEST(test_matrix_read_incorrect_m_neg)
{
    FILE *f = fopen("unit_tests/test_matrix_read_incorrect_m_neg.txt", "r");
    if (f)
    {
        node_t *head1 =matrix_read(f);
        ck_assert_ptr_null(head1);
    }
    else
        printf("Couldn't check4!\n");
}
END_TEST

START_TEST(test_matrix_read_incorrect_n_letter)
{
    FILE *f = fopen("unit_tests/test_matrix_read_incorrect_n_letter.txt", "r");
    if (f)
    {
        node_t *head1 =matrix_read(f);
        ck_assert_ptr_null(head1);
    }
    else
        printf("Couldn't check5!\n");
}
END_TEST

START_TEST(test_matrix_read_incorrect_m_float)
{
    FILE *f = fopen("unit_tests/test_matrix_read_incorrect_m_float.txt", "r");
    if (f)
    {
        node_t *head1 =matrix_read(f);
        ck_assert_ptr_null(head1);
    }
    else
        printf("Couldn't check6!\n");
}
END_TEST

START_TEST(test_matrix_read_incorrect_value_float)
{
    FILE *f = fopen("unit_tests/test_matrix_read_incorrect_value_float.txt", "r");
    if (f)
    {
        node_t *head1 =matrix_read(f);
        ck_assert_ptr_null(head1);
    }
    else
        printf("Couldn't check7!\n");
}
END_TEST

START_TEST(test_matrix_read_incorrect_value_letter)
{
    FILE *f = fopen("unit_tests/test_matrix_read_incorrect_value_letter.txt", "r");
    if (f)
    {
        node_t *head1 =matrix_read(f);
        ck_assert_ptr_null(head1);
    }
    else
        printf("Couldn't check8!\n");
}
END_TEST

START_TEST(test_matrix_read_all_null_11)
{
    FILE *f = fopen("unit_tests/test_matrix_read_all_null_11.txt", "r");
    if (f)
    {
        node_t *head1 =matrix_read(f);
        ck_assert_ptr_null(head1);
    }
    else
        printf("Couldn't check9!\n");
}
END_TEST

START_TEST(test_matrix_read_one_nonnull_22)
{
    FILE *f = fopen("unit_tests/test_matrix_read_one_nonnull_22.txt", "r");
    if (f)
    {
        node_t *head1 =matrix_read(f);
        ck_assert_ptr_nonnull(head1);
        node_t node = {0, 0, 1, NULL};
        ck_assert_int_eq(matrix_eq(head1, &node), 1);
        matrix_free(head1);
    }
    else
        printf("Couldn't check10!\n");
}
END_TEST

START_TEST(test_matrix_read_usual_43)
{
    FILE *f = fopen("unit_tests/test_matrix_read_usual_43.txt", "r");
    if (f)
    {
        node_t *head1 =matrix_read(f);
        ck_assert_ptr_nonnull(head1);
        node_t node3 = {3, 2, 32, NULL};
        node_t node2 = {3, 0, 30, &node3};
        node_t node1 = {1, 1, 11, &node2};

        ck_assert_int_eq(matrix_eq(head1, &node1), 1);
        matrix_free(head1);
    }
    else
        printf("Couldn't check11!\n");
}
END_TEST

Suite* matrix_read_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("matrix_read");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_matrix_read_empty_file);
    tcase_add_test(tc_neg, test_matrix_read_not_enough);
    tcase_add_test(tc_neg, test_matrix_read_incorrect_n_0);
    tcase_add_test(tc_neg, test_matrix_read_incorrect_m_neg);
    tcase_add_test(tc_neg, test_matrix_read_incorrect_n_letter);
    tcase_add_test(tc_neg, test_matrix_read_incorrect_m_float);
    tcase_add_test(tc_neg, test_matrix_read_incorrect_value_float);
    tcase_add_test(tc_neg, test_matrix_read_incorrect_value_letter);
    tcase_add_test(tc_neg, test_matrix_read_all_null_11);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_matrix_read_usual_43);
    tcase_add_test(tc_pos, test_matrix_read_one_nonnull_22);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_matrix_insert_end_empty_list)
{
    node_t *head = NULL;
    node_t node = {1, 10, 5, NULL};
    head = matrix_insert_end(head, &node);
    ck_assert_ptr_nonnull(head);
    ck_assert_int_eq(matrix_eq(head, &node), 1);
}
END_TEST

START_TEST(test_matrix_insert_end_1_elem_in_list)
{
    node_t node1 = {1, 10, 5, NULL};
    node_t *head = &node1;
    node_t node2 = {0, 0, 0, NULL};
    head = matrix_insert_end(head, &node2);
    ck_assert_ptr_nonnull(head);
    ck_assert_ptr_eq(head, &node1);
    head = head->next;
    ck_assert_ptr_eq(head, &node2);
    head = head->next;
    ck_assert_ptr_null(head);
}
END_TEST

START_TEST(test_matrix_insert_end_usual)
{
    node_t node2 = {0, 0, 0, NULL};
    node_t node1 = {1, 10, 5, &node2};
    node_t *head = &node1;

    node_t node3 = {3, 3, 3, NULL};

    head = matrix_insert_end(head, &node3);
    ck_assert_ptr_nonnull(head);
    ck_assert_ptr_eq(head, &node1);
    head = head->next;
    ck_assert_ptr_eq(head, &node2);
    head = head->next;
    ck_assert_ptr_eq(head, &node3);
    head = head->next;
    ck_assert_ptr_null(head);
}
END_TEST

Suite* matrix_insert_end_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("matrix_insert_end");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_matrix_insert_end_empty_list);
    tcase_add_test(tc_neit, test_matrix_insert_end_1_elem_in_list);
    tcase_add_test(tc_neit, test_matrix_insert_end_usual);

    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_matrix_add_result_null)
{
    //2x2
    node_t node1_2 = {1, 0, -2, NULL};
    node_t node1_1 = {0, 1, 1, &node1_2};
    node_t *head1 = &node1_1;

    //2x2
    node_t node2_2 = {1, 0, 2, NULL};
    node_t node2_1 = {0, 1, -1, &node2_2};
    node_t *head2 = &node2_1;

    node_t *head_expected = NULL;
    node_t *head_got = matrix_add(head1, head2);

    ck_assert_int_eq(matrix_eq(head_expected, head_got), 1);
}
END_TEST

START_TEST(test_matrix_add_usual)
{
    //2x2
    node_t node1_3 = {1, 0, 1, NULL}; //result without summing
    node_t node1_2 = {0, 1, -1, &node1_3}; //result is sum = 0
    node_t node1_1 = {0, 0, 1, &node1_2}; //result is sum != 0
    node_t *head1 = &node1_1;

    //1x3
    node_t node2_3 = {0, 2, 2, NULL}; //result without summing
    node_t node2_2 = {0, 1, 1, &node2_3}; //result is sum = 0
    node_t node2_1 = {0, 0, 2, &node2_2}; //result is sum != 0
    node_t *head2 = &node2_1;

    //2x3
    node_t node3_3 = {1, 0, 1, NULL}; //result without summing from m1
    node_t node3_2 = {0, 2, 2, &node3_3}; //result without summing from  m2
    node_t node3_1 = {0, 0, 3, &node3_2}; //result is sum != 0
    node_t *head_expected = &node3_1;

    node_t *head_got = matrix_add(head1, head2);

//    printf("\nmatrix 1\n");
//    matrix_print(stdout, head1);
//    printf("\nmatrix 2\n");
//    matrix_print(stdout, head2);
//    printf("\nmatrix exp\n");
//    matrix_print(stdout, head_expected);
//    printf("\nmatrix got\n");
//    matrix_print(stdout, head_got);

    ck_assert_int_eq(matrix_eq(head_expected, head_got), 1);
    matrix_free(head_got);
}
END_TEST

Suite* matrix_add_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("matrix_add");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_matrix_add_result_null);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_matrix_add_usual);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_matrix_mul_result_null)
{
    //2x2
    node_t node1_4 = {1, 0, -2, NULL};
    node_t node1_3 = {1, 0, -2, &node1_4};
    node_t node1_2 = {1, 0, -2, &node1_3};
    node_t node1_1 = {0, 1, 1, &node1_2};
    node_t *head1 = &node1_1;

    //4x1
    node_t node2_3 = {0, 1, 1, NULL};
    node_t node2_2 = {1, 1, -1, &node2_3};
    node_t node2_1 = {4, 1, 1, &node2_2};
    node_t *head2 = &node2_1;

    node_t *head_expected = NULL;
    node_t *head_got = matrix_mul(head1, head2);

    ck_assert_int_eq(matrix_eq(head_expected, head_got), 1);
}
END_TEST

START_TEST(test_matrix_mul_usual)
{
    /*
     * 3x4
     * 0 0 0 0
     * 1 0 1 0
     * 0 1 0 1
    */
    node_t node1_4 = {2, 3, 1, NULL};
    node_t node1_3 = {2, 1, 1, &node1_4};
    node_t node1_2 = {1, 2, 1, &node1_3};
    node_t node1_1 = {1, 0, 1, &node1_2};
    node_t *head1 = &node1_1;

    /*3x5
     * 1 0 0 1 1
     * 0 1 0 0 0
     * 0 0 0 -1 1
    */
    node_t node2_6 = {2, 4, 1, NULL};
    node_t node2_5 = {2, 3, -1, &node2_6};
    node_t node2_4 = {1, 1, 1, &node2_5};
    node_t node2_3 = {0, 4, 1, &node2_4};
    node_t node2_2 = {0, 3, 1, &node2_3};
    node_t node2_1 = {0, 0, 1, &node2_2};
    node_t *head2 = &node2_1;

    /*3x5
     * 0 row and 2 col all empty
     * * - result of multing
     * 0  0  0  0  0
     * 1* 0  0  0* 2*
     * 0  1* 0  0  0
    */
    node_t node3_3 = {2, 1, 1, NULL};
    node_t node3_2 = {1, 4, 2, &node3_3};
    node_t node3_1 = {1, 0, 1, &node3_2};
    node_t *head_expected = &node3_1;

    node_t *head_got = matrix_mul(head1, head2);

//    printf("\nmatrix 1\n");
//    matrix_print(stdout, head1);
//    printf("\nmatrix 2\n");
//    matrix_print(stdout, head2);
//    printf("\nmatrix exp\n");
//    matrix_print(stdout, head_expected);
//    printf("\nmatrix got\n");
//    matrix_print(stdout, head_got);

    ck_assert_int_eq(matrix_eq(head_expected, head_got), 1);
    matrix_free(head_got);
}
END_TEST

Suite* matrix_mul_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("matrix_mul");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_matrix_mul_result_null);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_matrix_mul_usual);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_matrix_delete_result_null)
{
    node_t *head = NULL;

    node_t *node1 = node_create(1, 0, -2);
    if (node1)
    {
        head = matrix_insert_end(head, node1);
        node_t *node2 = node_create(1, 1, 1);
        if (node2)
        {
            head = matrix_insert_end(head, node2);

            node_t *head_got = matrix_delete_row_with_max(head);
            ck_assert_ptr_null(head_got);
        }
    }
}
END_TEST

START_TEST(test_matrix_delete_first) //also checcks if there are several rows with max
{
    node_t *head = NULL;

    node_t *node1 = node_create(1, 0, 100); //delete
    if (node1)
    {
        head = matrix_insert_end(head, node1);
        node_t *node2 = node_create(1, 1, 1); //delete
        if (node2)
        {
            head = matrix_insert_end(head, node2);
            node_t *node3 = node_create(3, 0, 1);
            if (node3)
            {
                head = matrix_insert_end(head, node3);
                node_t *node4 = node_create(5, 0, 100);
                if (node4)
                {
                    head = matrix_insert_end(head, node4);
                    node_t *head_got = matrix_delete_row_with_max(head);
                    node_t *cur = head_got;
                    ck_assert_ptr_eq(cur, node3);
                    ck_assert_int_eq(cur->i, 2);
                    ck_assert_int_eq(cur->j, 0);
                    ck_assert_int_eq(cur->value, 1);
                    cur = cur->next;
                    ck_assert_ptr_eq(cur, node4);
                    ck_assert_int_eq(cur->i, 4);
                    ck_assert_int_eq(cur->j, 0);
                    ck_assert_int_eq(cur->value, 100);
                    cur = cur->next;
                    ck_assert_ptr_null(cur);
                    matrix_free(head_got);
                }
            }
        }
    }
}
END_TEST

START_TEST(test_matrix_delete_middle)
{
    node_t *head = NULL;

    node_t *node1 = node_create(1, 0, -10);
    if (node1)
    {
        head = matrix_insert_end(head, node1);
        node_t *node2 = node_create(1, 1, -10);
        if (node2)
        {
            head = matrix_insert_end(head, node2);
            node_t *node3 = node_create(3, 0, -1); //delete
            if (node3)
            {
                head = matrix_insert_end(head, node3);
                node_t *node4 = node_create(5, 0, -10);
                if (node4)
                {
                    head = matrix_insert_end(head, node4);
                    node_t *head_got = matrix_delete_row_with_max(head);
                    node_t *cur = head_got;
                    ck_assert_ptr_eq(cur, node1);
                    ck_assert_int_eq(cur->i, 1);
                    ck_assert_int_eq(cur->j, 0);
                    ck_assert_int_eq(cur->value, -10);
                    cur = cur->next;
                    ck_assert_ptr_eq(cur, node2);
                    ck_assert_int_eq(cur->i, 1);
                    ck_assert_int_eq(cur->j, 1);
                    ck_assert_int_eq(cur->value, -10);
                    cur = cur->next;
                    ck_assert_ptr_eq(cur, node4);
                    ck_assert_int_eq(cur->i, 4);
                    ck_assert_int_eq(cur->j, 0);
                    ck_assert_int_eq(cur->value, -10);
                    cur = cur->next;
                    ck_assert_ptr_null(cur);
                    matrix_free(head_got);
                }
            }
        }
    }
}
END_TEST

START_TEST(test_matrix_delete_end)
{
    node_t *head = NULL;

    node_t *node1 = node_create(1, 0, -10);
    if (node1)
    {
        head = matrix_insert_end(head, node1);
        node_t *node2 = node_create(1, 1, -10);
        if (node2)
        {
            head = matrix_insert_end(head, node2);
            node_t *node3 = node_create(5, 0, -10); //delete
            if (node3)
            {
                head = matrix_insert_end(head, node3);
                node_t *node4 = node_create(5, 0, 1); //delete
                if (node4)
                {
                    head = matrix_insert_end(head, node4);
                    node_t *head_got = matrix_delete_row_with_max(head);
                    node_t *cur = head_got;
                    ck_assert_ptr_eq(cur, node1);
                    ck_assert_int_eq(cur->i, 1);
                    ck_assert_int_eq(cur->j, 0);
                    ck_assert_int_eq(cur->value, -10);
                    cur = cur->next;
                    ck_assert_ptr_eq(cur, node2);
                    ck_assert_int_eq(cur->i, 1);
                    ck_assert_int_eq(cur->j, 1);
                    ck_assert_int_eq(cur->value, -10);
                    cur = cur->next;
                    ck_assert_ptr_null(cur);
                    matrix_free(head_got);
                }
            }
        }
    }
}
END_TEST

Suite* matrix_delete_row_with_max_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("matrix_delete_row_with_max");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_matrix_delete_result_null);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_matrix_delete_first);
    tcase_add_test(tc_pos, test_matrix_delete_middle);
    tcase_add_test(tc_pos, test_matrix_delete_end);
    suite_add_tcase(s, tc_pos);

    return s;
}
