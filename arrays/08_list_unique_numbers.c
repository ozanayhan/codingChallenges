#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define  SIZE 20

int main(void)
{
	int a[SIZE];
	
	srand((unsigned)time(NULL));

	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % SIZE;
		printf("%d ", a[i]);
	}
	
	printf("\n");

	int idx = 0;
	int key;
	for (int i = 0; i < SIZE; ++i) 
	{
		key = a[i];
		int j;
		for (j = 0; j < SIZE; ++j) 
		{
			if (a[j] == key && i != j)
			{
				// not a unique number
				break;
			}
		}
		if (j == SIZE)
		{
			// unique number
			a[idx++] = key;
		}
	}
	for (int i = 0; i < idx; ++i) 
	{
		printf("%d ", a[i]);
	}

}