// Finds the biggest Armstrong number(*) up to a user-given number N.

// Copyright (C) 2025 O. Ayhan

// (*) In number theory, a narcissistic number (also known as an Armstrong number,
// or a plus perfect number) in a given number base b is a number that is
// the sum of its own digits each raised to the power of the number of digits.
// (Source: Wikipedia)

#include <stdio.h>
int isarmstrong(int number)
{
    int no_of_digits = 0;         // initialize number of digits as 0.
    int digit_power = 1;          // initialize the nth power of digit as 1.
    int sum_of_digits_powers = 0; // initialize the sum of nth powers of all digits as 0.
    int number_temp1 = number;    // initialize the temporary variable 1 with the input number.
    while (number_temp1)
    {
        int number_temp2 = number_temp1; // initialize the temporary variable 2 with the temporary variable 1.
        int j = 0;                       // number of digits counter.
        while (number_temp2 || j < no_of_digits)
        {
            digit_power = digit_power * (number_temp1 % 10); // calculate the nth power of the digit
            number_temp2 /= 10;
            j++;
        }
        no_of_digits = j;
        number_temp1 /= 10;
        sum_of_digits_powers += digit_power;
        digit_power = 1;
    }
    if (sum_of_digits_powers == number)
        return 1;
    return 0;
}

int main(void)
{
    int N;
    printf("Please enter a Number N: ");
    scanf("%d", &N);
    int i = N;
    while (i)
    {
        if (isarmstrong(i))
        {
            printf("The biggest Armstrong number up to %d is %d", N, i);
            return 0;
        }
        i--;
    }
}