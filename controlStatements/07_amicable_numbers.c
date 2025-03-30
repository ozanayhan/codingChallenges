// Checks if the two numbers (x, y) given by the user are amicable numbers (*).

// Copyright (C) 2025 O. Ayhan

// (*) In mathematics, the amicable numbers are two different natural numbers
// related in such a way that the sum of the proper divisors of each is
// equal to the other number.
// The smallest pair of amicable numbers is (220, 284). 
// They are amicable because the proper divisors of 220 are 
// 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110, of which the sum is 284;
// and the proper divisors of 284 are 1, 2, 4, 71 and 142, of which the sum is 220.
// (Source: Wikipedia)

#include <stdio.h>
int arefriends(int x, int y)
{
    int sum_factor_x = 1;
    int sum_factor_y = 1;
    for (int i = 2; i <= ((x > y ? x : y) / 2); i++)
    {
        sum_factor_x = sum_factor_x + (x % i == 0 ? i : 0);
        sum_factor_y = sum_factor_y + (y % i == 0 ? i : 0);
    }
    if (sum_factor_x == y && sum_factor_y == x)
        return 1;
    return 0;
}
int main(void)
{
    int x, y;
    printf("Please enter 2 numbers: ");
    scanf("%d%d", &x, &y);
    printf("The numbers %d and %d are%samicable numbers", x, y, arefriends(x, y) ? " " : " not ");
}