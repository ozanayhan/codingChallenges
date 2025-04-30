// Finds the sub sequent array inside an array that has the maximum sum.

// Copyright (C) 2025 O. Ayhan

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void)
{
    int a[SIZE];

    srand((unsigned)time(0));
    for (int i = 0; i < SIZE; ++i)
    {
        a[i] = rand() % 20 - 15;
    }
    //int a[SIZE] = {-2, -20, -17, -16, -3, -19, -16, -18, -10, -8};
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", a[i]);
    }

    int valSum = 0;
    int maxSum = INT_MIN;
    int idx = 0;
    int idxStart = 0;
    int idxStartMax = 0;
    int idxEnd = 0;

    for (idx = 0; idx < SIZE; ++idx)
    {
        valSum += a[idx];
        if (valSum > maxSum)
        {
            idxEnd = idx;
            idxStartMax = idxStart;
            maxSum = valSum;
        }
        if (valSum < 0)
        {
            idxStart = idx + 1;
            valSum = 0;
        }

    }
    printf("\n");
    printf("Starting Position: %d ", idxStartMax);
    printf("\n");
    printf("Ending Position: %d ", idxEnd);
}