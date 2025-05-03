// Finds the most repeating number in an array.

// Copyright (C) 2025 O. Ayhan
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define     SIZE      1000

int main(void)
{

	int a[SIZE];

	srand((unsigned)time(0));

	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 500;
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", a[i]);
	}

    int maxCnt = 0;
    int cnt;
    int mode;
    for (int i = 0; i < SIZE; ++i) {
        cnt = 0;
		for (int j = 0; j < SIZE; ++j) {
            if (a[i] == a[j])
            ++cnt;
        }
        if (cnt > maxCnt)
        {
            maxCnt = cnt;
            mode = a[i];
        }
	}
    printf("\n");
    printf("Max repeating number is %d, and there are %d occurences.", mode, maxCnt);
}