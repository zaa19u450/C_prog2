#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#define MAXLEN 30

#include <check.h>
#include "my_snprintf.h"

int worked_cor(char *exp_s, char *my_s, int exp_out, int my_out);

Suite* nosp_suite(void);
Suite* s_suite(void);
Suite* lld_suite(void);
Suite* ho_suite(void);
Suite* combo_suite(void);

#endif // CHECK_MAIN_H
