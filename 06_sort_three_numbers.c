#include <stdio.h>

int main(void)
{
    int x, y, z;
    printf("uc tamsayi giriniz: ");
    scanf("%d%d%d", &x, &y, &z);

    int big = x > y ? x : y;
    int small = x > y ? y : x;
    big = big > z ? big : z;
    small = small < z ? small : z;
    int middle = x > small && x < big ? x : y > small && y < big ? y : x == y ? x : z;
    

    printf("%d %s %d %s %d\n" , small, small == middle ? "=" : "<", middle, middle == big ? "=" : "<", big);

}