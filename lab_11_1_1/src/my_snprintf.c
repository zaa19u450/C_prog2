#include "my_snprintf.h"
#include <stdarg.h>
#include <stdio.h>

//s, lld, ho
int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...)
{
    size_t cur_n = 0;

    char *s_param = NULL;
    int64_t lld_param;
    uint16_t ho_param;

    va_list vl;
    va_start(vl, format);

    //start
    for (; *format; format++)
    {
        //no specificator
        if (*format != '%')
        {
            if (s && n && (cur_n < n))
                s[cur_n] = *format;
            cur_n++;
        }
        else
        //met %
        {
            //specificator %s
            if (*(format + 1) == 's')
            {
                for (s_param = va_arg(vl, char *); *s_param; s_param++, cur_n++)
                    if (s && n && cur_n < n)
                        s[cur_n] = *s_param;

                format++;
                continue;
            }
            //specificator lld
            else if (*(format + 1) == 'l' && *(format + 2) == 'l' && *(format + 3) == 'd')
            {
                lld_param = va_arg(vl, int64_t);

                //write sign
                if (lld_param < 0)
                {
                    if (s && n && cur_n < n)
                        s[cur_n] = '-';
                    lld_param *= -1;
                    cur_n++;
                }

                int zeroes;
                uint64_t lld_param_rev = reverse(lld_param, &zeroes);

                //write digits
                if (lld_param_rev == 0)
                {
                    if (s && n && cur_n < n)
                        s[cur_n] = '0';
                    cur_n++;
                }
                while (lld_param_rev)
                {
                    if (s && n && cur_n < n)
                        s[cur_n] = digit_to_char(lld_param_rev % 10);
                    cur_n++;
                    lld_param_rev /= 10;
                }
                //write meaning zeroes
                while (zeroes)
                {
                    if (s && n && cur_n < n)
                        s[cur_n] = '0';
                    cur_n++;
                    zeroes--;
                }
                format += 3;
                continue;
            }
            //specificator ho
            else if (*(format + 1) == 'h' && *(format + 2) == 'o')
            {
                //int because of warning
                ho_param = va_arg(vl, int);
                uint32_t ho_result = from10_to8(ho_param);
                int zeroes;
                ho_result = reverse(ho_result, &zeroes);

                //write digits
                if (ho_result == 0)
                {
                    if (s && n && cur_n < n)
                        s[cur_n] = '0';
                    cur_n++;
                }
                while (ho_result)
                {
                    if (s && n && cur_n < n)
                        s[cur_n] = digit_to_char(ho_result % 10);
                    ho_result /= 10;
                    cur_n++;
                }
                //write meaning zeroes
                while (zeroes)
                {
                    if (s && n && cur_n < n)
                        s[cur_n] = '0';
                    cur_n++;
                    zeroes--;
                }
                format += 2;
                continue;
            }
            //unknown specificator
            else
            {
                if (s && n && cur_n < n)
                    s[cur_n] = '%';
                cur_n++;
            }
        }
    }
    //end
    va_end(vl);
    //add end of string
    if (s && n)
    {
        if (cur_n < n)
            s[cur_n] = '\0';
        else
            s[n - 1] = '\0';
    }
    return cur_n;
}

int my_pow(int x, int n)
{
    int result = 1;
    for (int i = 0; i < n; i++, result *= x);
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
        result += cur * my_pow(10, cur_i);
        x = x / 8;
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







