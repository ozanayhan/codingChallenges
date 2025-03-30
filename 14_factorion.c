#include <stdio.h>

#define FACTORIAL_ARRAY ((int[]){1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880})

int main(void)
{

    for (int i = 1; i < 10000000; i++) 
    {
        long long sum_digit_factorial = 0;
        int base_number = i;
        while (base_number) 
        {
            sum_digit_factorial += FACTORIAL_ARRAY[(base_number % 10)];
            base_number /= 10;
        }
        if (sum_digit_factorial == i)
        printf("%d is a factorion\n", i);
    }


}