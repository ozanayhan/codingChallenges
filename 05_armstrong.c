#include <stdio.h>

int isarmstrong(int number) 
{
    int no_of_digits = 0; // initialize number of digits as 0, because it is not yet calculated.
    int digit_power = 1; // initialize the nth power of digit as 1.
    int sum_of_digits_powers = 0; // initialize the sum of nth powers of all digits as 0.

    int number_temp1 = number; // initialize the temporary variable 1 with the input number.

    while (number_temp1) {
    int number_temp2 = number_temp1; // initialize the temporary variable 2 with the temporary variable 1.
    int j = 0; // number of digits counter.
    while (number_temp2 || j < no_of_digits)
    {
        digit_power = digit_power * (number_temp1 % 10); //calculate the nth power of the digit
        number_temp2 /= 10;
        j++;
    }
    no_of_digits = j;
    number_temp1 /= 10;
    sum_of_digits_powers += digit_power;
    digit_power = 1;
    }
    if (sum_of_digits_powers == number)
    return 1;
    return 0;

    //
}

int main(void)
{
    for (int i = 999999999; i > 100000000; i--) 
    {
        if (isarmstrong(i)) {
        printf("the biggest 9-digit armstrong number is: %d", i);
        return 0;
        }
    }
}