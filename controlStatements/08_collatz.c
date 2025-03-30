#include <stdio.h>

unsigned display_collatz(unsigned long long val) {
    
    int next_num = val;
    int count = 0;
    while (next_num != 1) {
        printf("%d ", next_num);
        next_num = next_num % 2 == 0 ? next_num / 2 : 3 * next_num + 1;
        ++count;
    }
    //Add the number 1 at the end.
    printf("1\n");
    printf("Total number of terms is: %d", ++count);
    return count;
}

int main(void)
{
    long long x;
    printf("bir tamsayi giriniz: ");
    scanf("%d", &x);
    display_collatz(x);
}