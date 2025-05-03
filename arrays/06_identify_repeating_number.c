#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define   SIZE      100

int main(void)
{
	int a[SIZE];
	
	srand((unsigned)time(NULL));
	int val = rand() % (SIZE - 1) + 1;
	a[0] = val;

	for (int i = 1; i < SIZE; ++i) {
		a[i] = i;
	}

	for (int i = 0; i < 5 * SIZE; ++i) {
		int idx1 = rand() % SIZE;
		int idx2 = rand() % SIZE;
		if (idx1 != idx2) {
			int temp = a[idx1];
			a[idx1] = a[idx2];
			a[idx2] = temp;
		}
	}

	for (int i = 0; i < SIZE; ++i) {
		if (i % 20 == 0)
			printf("\n");
		printf("%3d ", a[i]);
	}

	printf("\ntekrar eden sayi : %d\n", val);

	//a dizisi icinde tekrar eden sayiyi bulacak kodu buraya yazınız:

	int c[SIZE] = { 0 };
	for (int i = 0; i < SIZE; ++i) 
	{
		++c[a[i]];
		if (c[a[i]] == 2)
		{
			printf("\ntekrar eden sayi : %d\n", a[i]);
			return 0;
		}
	}
}