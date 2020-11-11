#include "check_main.h"

//my_comarator
START_TEST(test_my_comparator_equal)
{
    data_t data1 = {"Test", 1};
    data_t data2 = {"Test", 1};

    int rc = my_comparator(&data1, &data2);

    ck_assert_int_eq(rc, 0);
}
END_TEST


START_TEST(test_my_comparator_diffeq_namesmaller)
{
    data_t data1 = {"Test", 1};
    data_t data2 = {"Test1", 1};

    int rc = my_comparator(&data1, &data2);

    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_my_comparator_diffeq_namebigger)
{
    data_t data1 = {"Test1", 1};
    data_t data2 = {"Test", 1};

    int rc = my_comparator(&data1, &data2);

    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(test_my_comparator_diffbigger_nameeq)
{
    data_t data1 = {"Test", 2};
    data_t data2 = {"Test", 1};

    int rc = my_comparator(&data1, &data2);

    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(test_my_comparator_diffsmaller_nameeq)
{
    data_t data1 = {"Test", 1};
    data_t data2 = {"Test", 2};

    int rc = my_comparator(&data1, &data2);

    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_my_comparator_diffsmaller_namebigger)
{
    data_t data1 = {"Test1", 1};
    data_t data2 = {"Test", 2};

    int rc = my_comparator(&data1, &data2);

    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_my_comparator_diffbigger_namesmaller)
{
    data_t data1 = {"Test", 2};
    data_t data2 = {"Test1", 1};

    int rc = my_comparator(&data1, &data2);

    ck_assert_int_eq(rc, 1);
}
END_TEST

Suite* my_comparator_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("my_comparator");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_my_comparator_equal);
    tcase_add_test(tc_neit, test_my_comparator_diffeq_namesmaller);
    tcase_add_test(tc_neit, test_my_comparator_diffeq_namebigger);
    tcase_add_test(tc_neit, test_my_comparator_diffbigger_nameeq);
    tcase_add_test(tc_neit, test_my_comparator_diffsmaller_nameeq);
    tcase_add_test(tc_neit, test_my_comparator_diffsmaller_namebigger);
    tcase_add_test(tc_neit, test_my_comparator_diffbigger_namesmaller);

    suite_add_tcase(s, tc_neit);

    return s;
}
