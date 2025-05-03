// Displays the vertical histogram of an array.

// Copyright (C) 2025 O. Ayhan


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define			SIZE		20

int main(void)
{
	int a[SIZE];
	srand((unsigned)time(0));
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % SIZE + 1;
		printf("%d  ", a[i]);
	}
	printf("\n");
    printf("\n");

    // Create an array that contains the information wheter a value is present in the array.
    int maxAr = a[0];
    int minAr = a[0];
    for (int i = 1; i < SIZE; ++i) {
		if (a[i] > maxAr)
        maxAr = a[i];
        else if (a[i] < minAr)
        minAr = a[i];
	}
    for (int i = maxAr; i > 0; --i) 
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (a[j] >= i)
            printf(" * ");
            else
            printf("   ");
        }
        printf("\n");
    }
    
}