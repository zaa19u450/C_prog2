#include "functions.h"

int my_pow(int x, int n)
{
    int result = 1;
    for (int i = 0; i < n; i++, result *= x)
        ;
    return result;
}

uint32_t from10_to8(uint16_t x)
{
    uint32_t result = 0;
    uint32_t cur;
    unsigned int cur_i = -1;

    while (x)
    {
        cur = x % 8;
        cur_i++;
        x = x / 8;
        result += cur * my_pow(10, cur_i);
    }

    return result;
}

uint64_t reverse(int64_t x, int *zeroes)
{
    int sign = 1;
    if (x < 0)
    {
        sign = -1;
        x *= -1;
    }

    uint64_t result = 0;
    int meaning0_amount = 0;
    int cur_digit;

    while (x)
    {
        cur_digit = x % 10;
        if (!cur_digit && !result)
            meaning0_amount++;
        else
            result = result * 10 + cur_digit;
        x /= 10;
    }

    result *= sign;
    *zeroes = meaning0_amount;
    return result;
}

char digit_to_char(int digit)
{
    char *alphabet = "0123456789";
    return alphabet[digit];
}

