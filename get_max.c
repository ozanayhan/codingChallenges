#include <stdio.h>
int max(int x1, int x2, int x3)
{
    int a = x1 > x2 ? x1 : x2;
    int b = a > x3 ? a : x3;
    return b;

}

int main(void)
{
    int x_val_1 = 9;
    int x_val_2 = 5;
    int x_val_3 = 3;
    int result = max(x_val_1, x_val_2, x_val_3);
    printf("Max value of %d, %d and %d is %d\n" , x_val_1, x_val_2, x_val_3, result);

}