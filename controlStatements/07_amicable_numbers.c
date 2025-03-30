#include <stdio.h>
int arefriends(int x, int y)
{
    int sum_factor_x = 1;
    int sum_factor_y = 1;
    for (int i = 2; i <= ((x > y ? x : y) / 2); i++) {
        sum_factor_x = sum_factor_x + (x % i == 0 ? i : 0);
        sum_factor_y = sum_factor_y + (y % i == 0 ? i : 0);
    }
    if (sum_factor_x == y && sum_factor_y == x)
    return 1;
    return 0;

}

int main(void)
{
    int x, y;
    printf("iki tamsayi giriniz: ");
    scanf("%d%d", &x, &y);

    printf("The numbers %d and %d are%samicable numbers" , x, y, arefriends(x, y) ? " " : " not ");

}