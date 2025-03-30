// Finds the digital root (*) of a user-given number N.

// Copyright (C) 2025 O. Ayhan

// (*) The digital root (also repeated digital sum) of a natural number 
// in a given radix is the (single digit) value obtained 
// by an iterative process of summing digits, on each iteration 
// using the result from the previous iteration to compute a digit sum.
// The process continues until a single-digit number is reached. 
// For example, in base 10, the digital root of the number 12345 is 6 
// because the sum of the digits in the number is 1 + 2 + 3 + 4 + 5 = 15, 
// then the addition process is repeated again for the resulting number 15,
// so that the sum of 1 + 5 equals 6, which is the digital root of that number.
// (Source: Wikipedia)
#include <stdio.h>
int digital_root(int x)
{
    int number_temp = x;
    int temp_sum = 0;
    do {
        temp_sum = 0;
        while (number_temp) {
            temp_sum += number_temp % 10;
            number_temp /= 10;
        }
        number_temp = temp_sum;
    }while (temp_sum / 10);
    return temp_sum;
}
int main(void)
{
    int x;
    printf("Please enter a number: ");
    scanf("%d", &x);
    printf("Digital Root of %d is %d\n" , x, digital_root(x));
}