// Finds if the sum of three numbers in three different arrays equal a certain value.
// The objective is to achieve this with a complexity less that O(n3).
// The below algorithm achieves O(n2logn)

// Copyright (C) 2025 O. Ayhan

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int icmp(const void* vp1, const void* vp2)
{
    return *(const int*)vp1 - *(const int*)vp2;
}

int main(void)
{
    int a1[SIZE];
    int a2[SIZE];
    int a3[SIZE];
    srand((unsigned)time(0));
    for (int i = 0; i < SIZE; ++i)
    {
        a1[i] = rand() % SIZE + 1;
        a2[i] = rand() % SIZE + 1;
        a3[i] = rand() % SIZE + 1;
    }

    // Step1: Add all the elements of the first 2 arrays in another array of n2 length. O(n2)
    int a_sum[SIZE * SIZE];

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            a_sum[ i * SIZE + j ] = a1[i] + a2[j];
        }
    }

    // Step2: Sort the new array a_sum in ascending order with quick sort. O(n2*log(n2)) = O(n2 * 2logn) = O(n2logn)
    qsort(a_sum, SIZE*SIZE, sizeof(int), icmp);

    // print the arrays a1, a2 and a3.
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", a1[i]);
    }
    printf("\n");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", a2[i]);
    }
    printf("\n");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", a3[i]);
    }
    printf("\n");

    printf("Enter the value you would like to search.");
    int val;
    scanf("%d", &val);
    int key = val;

    // Step 3: Search the value key using the arrays a3[SIZE] and a_sum[SIZE*SIZE] using binary search. O(nlogn)
    int idx_start = 0;
    int idx_end = SIZE * SIZE - 1;
    int idx_mid;
    int temp_sum;
    int i;
    for (i = 0; i < SIZE; ++i)
    {
        while(idx_start <= idx_end)
        {
            idx_mid = (idx_end + idx_start) / 2;
            temp_sum = a_sum[idx_mid] + a3[i];
            if (temp_sum == key)
            goto out1;
            else if (temp_sum > key)
            idx_end = idx_mid - 1;
            else
            idx_start = idx_mid + 1;
        }
    }
    out1:
    if (idx_start > idx_end)
    printf("bulunamadi.");
    else
    printf("bulundu.");
    printf("\n");

    // Search the indices for the first 2 arrays a1[j] and a2[k] to make the sum a_sum[idx_mid]. O(n2)
    int j;
    int k;
    for (j = 0; j < SIZE; ++j)
    {
        for (k = 0; k < SIZE; ++k)
        {
            if (a_sum[ idx_mid ] == a1[j] + a2[k])
            {
                printf("a1 dizisinin %d indisli elemani.", j);
                printf("\n");
                printf("a2 dizisinin %d indisli elemani.", k);
                printf("\n");
                goto out2;
            }

        }
    }
    out2:
    printf("a3 dizisinin %d indisli elemani.", i);
}