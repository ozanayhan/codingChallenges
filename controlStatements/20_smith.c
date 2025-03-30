// Lists all the Smith numbers (*) up to a user given number N.

// Copyright (C) 2025 O. Ayhan

// (*) In number theory, a Smith number is a composite number for which, 
// in a given number base, the sum of its digits is equal to 
// the sum of the digits in its prime factorization in the same base. 
// (Source: Wikipedia)

#include <stdio.h>
// initialize the smallest prime number 2.
int smallest_prime = 2;
// initialize the biggest prime number up to the sqrt of x1 as 3.
// This value will be updated as bigger prime divisor numbers are found.
int biggest_prime_till_sqrt_of_x1 = 3;
// initialize the number of elements inside the prime array with 2 elements 
// Currently, (only 2 and 3 are in the list, so 2 elements).
int number_of_primes = 2;
 //initialize the variable to be checked starting with 4 (next number after 2 and 3);
int var_element = 4;
 // initialize calculated value of isprime as 1;
int isprime_calc = 1;
int get_digitsum(int x)
{
    int base_number = x;
    int digitsum = 0;
    while (base_number) 
    {
        digitsum += base_number % 10;
        base_number /= 10;
    }
    return digitsum;
}
void getprime_array(int size_prime_array, int prime_array[])
{   
    // iteration continues up to the square root of the number.
    while (var_element < size_prime_array) 
    {
        // Check if the number is divisible by any of the numbers that are contained inside the prime number array.
        for (int j = 0; j < number_of_primes; j++) {
            // Calculate a temporary assesment whether the number is prime
            // based on whether it is divisible by the element prime_array[j].
            isprime_calc = ((var_element % prime_array[j]) == 0) ? 0 : 1;
            // Break, if it is divisible.
            if (isprime_calc == 0) {
                break;
            }      
        }
        // If the iteration ended with an assessment isprime_calc == 1,
        // append the array with the current value of var_element,
        // and, increment the number of primes.
        if (isprime_calc == 1) {
            prime_array[number_of_primes] = var_element;
            biggest_prime_till_sqrt_of_x1 = var_element;
            ++number_of_primes;
        }
        // End of for loop for the current var_element.
        // Increment var_element by 1.
        ++var_element;
    }
}
int main(void)
{
    int x;
    printf("Please enter a number up to which all the Smith numbers will be displayed: ");
    scanf("%d", &x);
    int prime_array[x];
    // Fill the arrays elements for the first 2 elements.
    prime_array[0] = smallest_prime;
    prime_array[1] = biggest_prime_till_sqrt_of_x1;
    getprime_array(x, prime_array);
    for (int i = 1; i <= x; i++) {
        int j = 0;
        int sum_factors = 0;
        int base_number = i;
        while (prime_array[j] <= (i/2)) {
            if (base_number % prime_array[j]) {
                j++;
            }
            else {
                sum_factors += get_digitsum(prime_array[j]);
                base_number /= prime_array[j];
            }
        }
        if (get_digitsum(i) == sum_factors)
        printf("%d is a Smith Number\n", i);
    }
}