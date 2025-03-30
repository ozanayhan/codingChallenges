#include <stdio.h>
int digital_root(int x)
{
    int number_temp = x;
    int temp_sum = 0;
    do {
        temp_sum = 0;
        while (number_temp) {
            temp_sum += number_temp % 10;
            number_temp /= 10;
        }
        number_temp = temp_sum;
    }while (temp_sum / 10);
    return temp_sum;
}

int main(void)
{
    int x;
    printf("bir tamsayi giriniz: ");
    scanf("%d", &x);

    printf("Digital Root of %d is %d\n" , x, digital_root(x));

}