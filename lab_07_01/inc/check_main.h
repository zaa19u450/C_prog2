#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>
#include "main_header.h"
#include "key.h"
#include "mysort.h"
#include "count_amount.h"
#include "int_cmp.h"
#include "swap.h"

#define EPS 1e-7

Suite *count_amount_suite(void);
Suite *int_cmp_suite(void);
Suite *key_suite(void);
Suite *mysort_suite(void);
Suite *swap_suite(void);

#endif // CHECK_MAIN_H
