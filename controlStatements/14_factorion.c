// Lists all the Factorions (*) up to a user-given number N.

// Copyright (C) 2025 O. Ayhan

// (*) In number theory, a factorion in a given number base b
// is a natural number that equals the sum of the factorials of its digits.
// (Source: Wikipedia)

#include <stdio.h>
#define FACTORIAL_ARRAY ((int[]){1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880})
int main(void)
{
    int N;
    printf("Please enter a number up to which all factorions will be displayed: ");
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
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