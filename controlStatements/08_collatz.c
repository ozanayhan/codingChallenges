// Displays the Collatz series (*) of a user given number N.

// Copyright (C) 2025 O. Ayhan

// (*) The Collatz conjecture is one of the most famous unsolved problems in mathematics.
// The conjecture asks whether repeating two simple arithmetic operations 
// will eventually transform every positive integer into 1.
// It concerns sequences of integers in which each term is obtained from
// the previous term as follows: if a term is even, the next term is one half of it.
// If a term is odd, the next term is 3 times the previous term plus 1.
// The conjecture is that these sequences always reach 1, 
// no matter which positive integer is chosen to start the sequence.
// The conjecture has been shown to hold for all positive integers up to 2.95×10^20, 
// but no general proof has been found.
// (Source: Wikipedia)

#include <stdio.h>
unsigned display_collatz(unsigned long long val) {
    int next_num = val;
    int count = 0;
    while (next_num != 1) {
        printf("%d ", next_num);
        next_num = next_num % 2 == 0 ? next_num / 2 : 3 * next_num + 1;
        ++count;
    }
    printf("1\n");
    printf("Total number of terms until reaching 1 is: %d", ++count);
    return count;
}
int main(void)
{
    long long N;
    printf("Please enter a number N: ");
    scanf("%d", &N);
    display_collatz(N);
}