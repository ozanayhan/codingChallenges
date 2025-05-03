#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define   SIZE      100

int icmp(const void *vp1, const void *vp2)
{
	return *(const int *)vp1 > *(const int *)vp2 ? 1  :
         *(const int *)vp1 < *(const int *)vp2 ? -1 : 0;
}

int main(void)
{
	int a[SIZE];

	srand((unsigned)time(NULL));


	for (int i = 0, idx = 0; idx < SIZE; ++i) {
		if (rand() % (SIZE / 4) != 0)
			a[idx++] = i;
	}

	for (int i = 0; i < SIZE; ++i) {
		if (i != 0 && i % 20 == 0)
			printf("\n");
		printf("%3d ", a[i]);
	}
	printf("\n\n");

	int key = 0;

	for (int i = 0; i < SIZE; ++i) {
		if (a[i] != key)
		{
			printf("The smallest number that does not exist in the list is %d", key);
			return key;
		}
		++key;
	}
	printf("The smallest number that does not exist in the list is %d", key);
	return key;
}