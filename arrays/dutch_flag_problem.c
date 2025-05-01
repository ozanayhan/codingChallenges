// Sorts an array that consists of0, 1 and 2 only

// Copyright (C) 2025 O. Ayhan

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void sortThreeElements(int (*ar)[SIZE], int idxStart, int idxEnd, int i)
{
    int temp;
    if ((*ar)[idxStart] > (*ar)[i] && i > idxStart)
    {
        temp = (*ar)[idxStart];
        (*ar)[idxStart] = (*ar)[i];
        (*ar)[i] = temp;
    }
    if ((*ar)[i] > (*ar)[idxEnd] && idxEnd > i)
    {
        temp = (*ar)[i];
        (*ar)[i] = (*ar)[idxEnd];
        (*ar)[idxEnd] = temp;
    }
    if ((*ar)[idxStart] > (*ar)[i] && i > idxStart)
    {
        temp = (*ar)[idxStart];
        (*ar)[idxStart] = (*ar)[i];
        (*ar)[i] = temp;
    }
}

void updateIndices(int (*ar)[SIZE], int *idxStart, int *idxEnd, int i)
{
    int temp;
    if ((*ar)[*idxStart] == 0)
    {
        (++*idxStart);
    }
    if ((*ar)[i] == 0 && i > *idxStart)
    {
        temp = (*ar)[*idxStart];
        (*ar)[*idxStart] = (*ar)[i];
        (*ar)[i] = temp;
        (++*idxStart);
    }
    if ((*ar)[*idxEnd] == 0 && *idxEnd > *idxStart)
    {
        temp = (*ar)[*idxStart];
        (*ar)[*idxStart] = (*ar)[*idxEnd];
        (*ar)[i] = temp;
        (++*idxStart);
    }
    if ((*ar)[*idxEnd] == 2)
    {
        (--*idxEnd);
    }
    if ((*ar)[i] == 2 && *idxEnd > i)
    {
        temp = (*ar)[i];
        (*ar)[i] = (*ar)[*idxEnd];
        (*ar)[*idxEnd] = temp;
        (--*idxEnd);
    }
    if ((*ar)[*idxStart] == 2 && *idxEnd > *idxStart)
    {
        temp = (*ar)[*idxStart];
        (*ar)[*idxStart] = (*ar)[*idxEnd];
        (*ar)[*idxEnd] = temp;
        (--*idxEnd);
    }
}

int main(void)
{

    int a[SIZE];
    srand((unsigned)time(0));
    for (int i = 0; i < SIZE; ++i)
    {
         a[i] = rand() % 3;
         printf("%d", a[i]);
    }
    // int a[SIZE] = {2, 2, 1, 0, 1, 0, 0, 2, 0, 2, 0, 1, 2, 1, 0, 0, 1, 0, 2, 1};

    int idx_zero = 0;
    int idx_two = SIZE - 1;
    int temp;

    for (int i = 0; i < SIZE; ++i)
    {
        sortThreeElements(&a, idx_zero, idx_two, i);
        updateIndices(&a, &idx_zero, &idx_two, i);
        sortThreeElements(&a, idx_zero, idx_two, i);
        updateIndices(&a, &idx_zero, &idx_two, i);
    }
    printf("\n");
    printf("\n");
    printf("\n");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d", a[i]);
    }
}