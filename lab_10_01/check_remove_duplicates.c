#include "check_main.h"

START_TEST(test_remove_duplicates_empty_list)
{
    node_t *head = NULL;

    remove_duplicates(&head, my_comparator);
    ck_assert_ptr_null(head);
}
END_TEST

START_TEST(test_remove_duplicates_unsorted_list)
{
    data_t data1 = {"Test1", 1};
    data_t data2 = {"Test2", 2};
    data_t data3 = {"Test2", 2};
    data_t data4 = {"Test4", 0};

    node_t node4 = {&data4, NULL};
    node_t node3 = {&data3, &node4};
    node_t node2 = {&data2, &node3};
    node_t node1 = {&data1, &node2};
    node_t *head = &node1;

    remove_duplicates(&head, my_comparator);
    ck_assert_ptr_nonnull(head);
    ck_assert_int_eq(nodes_eq(head, &node1), 1);
    head = head->next;
    ck_assert_int_eq(nodes_eq(head, &node2), 1);
    head = head->next;
    ck_assert_int_eq(nodes_eq(head, &node3), 1);
    head = head->next;
    ck_assert_int_eq(nodes_eq(head, &node4), 1);
    head = head->next;
    ck_assert_ptr_null(head);
}
END_TEST

START_TEST(test_remove_duplicates_1elem_in_list)
{
    data_t data1 = {"Test1", 1};

    node_t node1 = {&data1, NULL};
    node_t *head = &node1;

    remove_duplicates(&head, my_comparator);
    ck_assert_ptr_nonnull(head);
    ck_assert_int_eq(nodes_eq(head, &node1), 1);
    head = head->next;
    ck_assert_ptr_null(head);
}
END_TEST

START_TEST(test_remove_2same_elems_in_list)
{
    data_t data1 = {"Test1", 1};
    data_t data2 = {"Test1", 1};

    node_t node2 = {&data2, NULL};
    node_t node1 = {&data1, &node2};
    node_t *head = &node1;

    remove_duplicates(&head, my_comparator);
    ck_assert_ptr_nonnull(head);
    ck_assert_int_eq(nodes_eq(head, &node1), 1);
    head = head->next;
    ck_assert_ptr_null(head);
}
END_TEST

START_TEST(test_remove_duplicates_no_duplicates)
{
    data_t data1 = {"Test1", 1};
    data_t data2 = {"Test2", 1};
    data_t data3 = {"Test3", 3};
    data_t data4 = {"Test3", 4};

    node_t node4 = {&data4, NULL};
    node_t node3 = {&data3, &node4};
    node_t node2 = {&data2, &node3};
    node_t node1 = {&data1, &node2};
    node_t *head = &node1;

    remove_duplicates(&head, my_comparator);
    ck_assert_ptr_nonnull(head);
    ck_assert_int_eq(nodes_eq(head, &node1), 1);
    head = head->next;
    ck_assert_int_eq(nodes_eq(head, &node2), 1);
    head = head->next;
    ck_assert_int_eq(nodes_eq(head, &node3), 1);
    head = head->next;
    ck_assert_int_eq(nodes_eq(head, &node4), 1);
    head = head->next;
    ck_assert_ptr_null(head);
}
END_TEST

START_TEST(test_remove_duplicates_usual)
{
    data_t data1 = {"Test1", 1};
    data_t data2 = {"Test1", 1};
    //
    data_t data3 = {"Test3", 3};
    //
    data_t data4 = {"Test3", 4};
    data_t data5 = {"Test3", 4};
    data_t data6 = {"Test3", 4};
    //
    data_t data7 = {"Test7", 4};
    data_t data8 = {"Test7", 4};

    node_t node8 = {&data8, NULL};
    node_t node7 = {&data7, &node8};
    node_t node6 = {&data6, &node7};
    node_t node5 = {&data5, &node6};
    node_t node4 = {&data4, &node5};
    node_t node3 = {&data3, &node4};
    node_t node2 = {&data2, &node3};
    node_t node1 = {&data1, &node2};
    node_t *head = &node1;

    remove_duplicates(&head, my_comparator);
    ck_assert_ptr_nonnull(head);

    ck_assert_int_eq(nodes_eq(head, &node1), 1);
    head = head->next;

    //no 2

    ck_assert_int_eq(nodes_eq(head, &node3), 1);
    head = head->next;

    ck_assert_int_eq(nodes_eq(head, &node4), 1);
    head = head->next;

    //no 5, 6

    ck_assert_int_eq(nodes_eq(head, &node7), 1);
    head = head->next;

    //no 8

    ck_assert_ptr_null(head);

    //duplicates are "deleted"
    ck_assert_ptr_null(node2.next);
    ck_assert_ptr_null(node5.next);
    ck_assert_ptr_null(node6.next);
    ck_assert_ptr_null(node8.next);
}
END_TEST

Suite* remove_duplicates_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("remove_duplicates");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_remove_duplicates_empty_list);
    tcase_add_test(tc_neg, test_remove_duplicates_unsorted_list);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_remove_duplicates_1elem_in_list);
    tcase_add_test(tc_pos, test_remove_2same_elems_in_list);
    tcase_add_test(tc_pos, test_remove_duplicates_no_duplicates);
    tcase_add_test(tc_pos, test_remove_duplicates_usual);
    suite_add_tcase(s, tc_pos);

    return s;
}
