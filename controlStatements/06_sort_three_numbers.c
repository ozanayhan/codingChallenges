// Displays the user given numbers x, y and z in ascending order.
// e.g.
// x = 5, y = 5, z = 3 is displayed as 3 < 5 = 5

// Copyright (C) 2025 O. Ayhan

#include <stdio.h>
int main(void)
{
    int x, y, z;
    printf("Please enter 3 Numbers that will be sorted: ");
    scanf("%d%d%d", &x, &y, &z);
    int big = x > y ? x : y;
    int small = x > y ? y : x;
    big = big > z ? big : z;
    small = small < z ? small : z;
    int middle = x > small && x < big ? x : y > small && y < big ? y
                                        : x == y                 ? x
                                                                 : z;
    printf("%d %s %d %s %d\n", small, small == middle ? "=" : "<", middle, middle == big ? "=" : "<", big);
}