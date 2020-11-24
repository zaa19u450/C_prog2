#include <stdio.h>
#include "functions.h"
#include "my_snprintf.h"
#include <stdint.h>

int main(void)
{
    setbuf(stdout, NULL);
    //int rc = 0;
    char s[30] = { '\0' };


    int n = 30;
    int x = 0;

    printf("lib: %d, %s.\n", snprintf(s, n, "%ho", x), s);
    printf("my : %d, %s.\n", my_snprintf(s, n, "%ho", x), s);

//    rc = snprintf(s, n, "%ho", x);
//    printf("rc = %d\n", rc);
//    printf("s = %s\n", s);
//    printf("my_result = %u", from10_to8(x));
//    printf("\n\n%d to %lld with %d zeroes", x, reverse(x, &z), z);

}

//int my_pow(int x, int n)
//{
//    int result = 1;
//    for (int i = 0; i < n; i++, result *= x)
//        ;
//    return result;
//}

//uint32_t from10_to8(uint16_t x)
//{
//    uint32_t result = 0;
//    uint32_t cur;
//    unsigned int cur_i = -1;

//    while (x)
//    {
//        cur = x % 8;
//        cur_i++;
//        x = x / 8;
//        result += cur * my_pow(10, cur_i);
//    }

//    return result;
//}
//int64_t reverse(int64_t x, int *zeroes)
//{
//    int sign = 1;
//    if (x < 0)
//    {
//        sign = -1;
//        x *= -1;
//    }

//    int64_t result = 0;
//    int meaning0_amount = 0;
//    int cur_digit;

//    while (x)
//    {
//        cur_digit = x % 10;
//        if (!cur_digit && !result)
//            meaning0_amount++;
//        else
//            result = result * 10 + cur_digit;
//        x /= 10;
//    }

//    result *= sign;
//    *zeroes = meaning0_amount;
//    return result;
//}


