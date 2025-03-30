#include <stdio.h>
int g = 20;

_Bool isodd(int x1)
{
    return 2*(x1/2) == x1 ? 0 : 1;

}

int main(void)
{
    int x_val_1 = 9;
    int x_val_2 = 10;

    int result1 = isodd(x_val_1);
    int result2 = isodd(x_val_2);
    printf("The value %d is odd? %s\n" , x_val_1, result1 == 1 ? "Y" : "N");
    printf("The value %d is odd? %s\n" , x_val_2, result2 == 1 ? "Y" : "N");
    printf("The value of g is %d\n" , g);

}