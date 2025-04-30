// Finds the consecutive sub-array inside an array that has the maximum sum.

// Copyright (C) 2025 O. Ayhan

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main(void)
{

    int a[SIZE] = {
        -3818, 7277, -5116, -1233, 259, -2731, -6153, 5436, 410, 2644,
    -3415, -3632, -4076, 3857, -2641, -7184, -7326, 159, 914, 369,
    -7894, -1036, 9549, 1294, 5087, -5822, 5926, 517, -616, 6796,
    -4567, 2919, 3926, -1523, 8237, -4524, -2910, -2450, -8904, 7021,
    -6811, -3598, 1502, -5544, 2990, -2191, 6920, 9696, 1849, 9697,
    -7348, 7370, 3492, -7189, 2994, -5041, 840, 7341, 3927, 6387,
    2790, 9683, 5612, 4786, 8913, 3554, -2784, 2276, 4639, -4315,
    -402, 5779, -3085, -6194, 2952, 2110, -3960, -2223, -827, 693,
    -3588, 8045, 7817, 7841, -6473, -670, -5681, 1050, -9041, -5381,
    -5371, -4239, -5563, 6075, -1485, -4082, -3931, -363, 1686, 5753,
      };
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", a[i]);
    }
    for (int i = 22; i < 83; ++i)
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
    printf("\n");
    printf("Maximum Subsequence: %d ", maxSum);
}