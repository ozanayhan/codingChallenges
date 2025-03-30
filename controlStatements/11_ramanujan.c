// Lists all the taxicab pairs (*) up to a user-given number N.

// Copyright (C) 2025 O. Ayhan

// (*) In mathematics, the nth taxicab number, typically denoted Ta(n) or Taxicab(n),
// is defined as the smallest integer that can be expressed as a sum of two 
// positive integer cubes in n distinct ways.
// The most famous taxicab number is 1729 = Ta(2) = 1^3 + 12^3 = 9^3 + 10^3, 
// also known as the Hardy–Ramanujan number.
// (Source: Wikipedia)

#include <stdio.h>
int isramanujan(int cube_sum, int a, int b) {
    int c = 0;
    int d = 0;
    int other_cube_sum = 0;
    while (1) {
        ++c;
        other_cube_sum = c * c * c + d * d * d;
        if (other_cube_sum == cube_sum && c != a && c != b && a * b * c * d != 0)
        printf("The number %d is a Ramanujan Number, because it is [(%d)cube + (%d)cube] and [(%d)cube + (%d)cube]\n", cube_sum, a, b, c, d);
        if (other_cube_sum > cube_sum) {
        if (c == d + 1)
        return 0;
        c = ++d;
        } 
    }
}
int main(void)
{
    int N;
    printf("Please enter a Number N, up to which all Ramanujan numbers will be listed: ");
    scanf("%d", &N);
    int a = 0;
    int b = 0;
    int cube_sum = 0;
    while (1) {
        ++a;
        cube_sum = a * a * a + b * b * b;
        // Check only numbers that can be expressed as sum of cubes.
        isramanujan(cube_sum, a, b);
        if (cube_sum > N) {
            if (a == b + 1)
            return 0;
            a = ++b;        
        }
        //printf("The numbers %d and %d are\n" , a, b);
    }
}