#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H

#define ERRUNKNOWN -1

#include <stdint.h>

int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...);

uint32_t from10_to8(uint16_t x);

int my_pow(int x, int n);

uint64_t reverse(int64_t x, int *zeroes);

char digit_to_char(int digit);

#endif // MY_SNPRINTF_H
