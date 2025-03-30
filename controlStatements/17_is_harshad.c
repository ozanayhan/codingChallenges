#include <stdio.h>
int is_harshad(int x)
{
    int base_number = x;
    int digitsum = 0;
    while (base_number) 
    {
        digitsum += base_number % 10;
        base_number /= 10;
    }
    if (!(x % digitsum))
    return 1;
    return 0;


}

int main(void)
{
    int x;
    printf("bir tamsayi giriniz: ");
    scanf("%d", &x);

if (is_harshad(x))
    printf("The number %d is a Harshad number" , x);
    else
    printf("The number %d is not a Harshad number" , x);
}