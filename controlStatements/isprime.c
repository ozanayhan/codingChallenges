// Checks if the user-given number N is prime, and lists
// all the prime numbers up to SQRT(N).

// Copyright (C) 2025 O. Ayhan

#include <stdio.h>
#include <math.h>
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
int isprime(int x1, int prime_array[])
{   
    // if x1 == 0 or 1, then it is not a prime.
    if (x1 == 1 || x1 == 0)
        return 0;
    // if x1 == 2 or 2, then it is a prime.
    if (x1 == 2 || x1 == 3)
        return 1;
    // Find the square root of the number to be used in the iteration.
    int sqrt_x1;
    sqrt_x1 = sqrt(x1);
    // iteration continues up to the square root of the number.
    while (var_element < sqrt_x1) 
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
            number_of_primes += 1;
        }
        // End of for loop for the current var_element.
        // Increment var_element by 1.
        var_element += 1;
    }
    // After obtaining the prime number array up to the square root of the number,
    // the input number will be checked against all the entries of the array.
    for (int k = 0; k < number_of_primes; k++) {
         int x1_prime = (x1 % prime_array[k]) == 0 ? 0 : 1;
         if (x1_prime == 0) {
            // if the number is divisible by any of the prime numbers inside the array, return 0.
            return 0;
         }
    }
    // Otherwise, return 1.
    return 1;
}
int main(void)
{
    int x_val_1;
    printf("Please enter a number to check if prime: ");
    scanf("%d", &x_val_1);
    int sqrt_x1;
    sqrt_x1 = sqrt(x_val_1);
    int prime_array[sqrt_x1];
    // Fill the arrays elements for the first 2 elements.
    prime_array[0] = smallest_prime;
    prime_array[1] = biggest_prime_till_sqrt_of_x1;
    printf("The value %d is prime? %s\n" , x_val_1, isprime(x_val_1, prime_array) ? "Y" : "N");
    printf("list of prime numbers up to the square root of %d are:\n", x_val_1);
    for (int m = 0; m < number_of_primes; m++) {
        printf("Number %d is: %d\n", m + 1, prime_array[m]);
    }
}