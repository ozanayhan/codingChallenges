// Finds the arrays consts of consecutive numbers with 2 different methods.

// Copyright (C) 2025 O. Ayhan
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int findMin(int (*a)[], int size)
{
    int minVal = (*a)[0];
    for (int i = 1; i < size; i++)
    {
        if ((*a)[i] < minVal)
            minVal = (*a)[i];
    }
    return minVal;
}

int isConsecutive(int (*a)[], int size, int minVal)
{
    int key = minVal;
    for (int i = 0; i < size; i++)
    {
        int j;
        for (j = 0; j < size; j++)
        {
            if ((*a)[j] == key)
            {
                // The consecutive number is found in the array.
                break;
            }
        }
        if (j == size)
        {
            // The consecutive number is not found inside the array.
            return 0;
        }
        ++key;
    }
    return 1;
}

int icmp(const void *vp1, const void *vp2)
{
    return *(const int *)vp1 - *(const int *)vp2;
}

int isConsecutiveSimple(int (*a)[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if ((*a)[i] != (*a)[i - 1] + 1)
        {
            // Not consecutive
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int a1[] = {74, 70, 73, 71, 83, 77, 84, 81, 82, 78, 86, 72, 79, 88, 76, 87, 75, 89, 80, 85};

    // METHOD 1: Without defining another array.
    // Step 1: Find minimum number inside the array. O(n)
    int minVal;
    int ConsecutiveArray;
    minVal = findMin(&a1, SIZE);
    // Step 2: Check if all the consecutive numbers starting with minVal are present in the array.
    ConsecutiveArray = isConsecutive(&a1, SIZE, minVal);
    if (ConsecutiveArray)
        printf("The array consists of consecutive numbers.");
    else
        printf("The array does not consist of consecutive numbers.");

    printf("\n");
    // METHOD 2: Using qsort.
    // Step1: Sort the array a1 in ascending order with quick sort. O(nlogn)
    qsort(a1, SIZE, sizeof(int), icmp);

    // Step2: Check if every element is 1 more than the previous array element. O(n)
    ConsecutiveArray = isConsecutiveSimple(&a1, SIZE);
    if (ConsecutiveArray)
        printf("The array consists of consecutive numbers.");
    else
        printf("The array does not consist of consecutive numbers.");
}