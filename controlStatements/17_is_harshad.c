// Checks if the user-given number x is a Harshad number (*).

// Copyright (C) 2025 O. Ayhan

// (*) In mathematics, a harshad number (or Niven number) in a given number base
// is an integer that is divisible by the sum of its digits when written in that base.
// (Source: Wikipedia)
#include <stdio.h>
int is_harshad(int x)
{
    int base_number = x;
    int digitsum = 0;
    while (base_number) 
    {
        digitsum += base_number % 10;
        base_number /= 10;
    }
    if (!(x % digitsum))
    return 1;
    return 0;
}
int main(void)
{
    int x;
    printf("Please enter a number to check if it is a Harshad number or not: ");
    scanf("%d", &x);

if (is_harshad(x))
    printf("The number %d is a Harshad number" , x);
    else
    printf("The number %d is not a Harshad number" , x);
}