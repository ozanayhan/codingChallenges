// Checks whether a user given string is a palindrome or not, but with the special condition
// that another array cannot be used and the string cannot be changed.

// Copyright (C) 2025 O. Ayhan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void sgets(char *p)
{
    int ch;
    int idx = 0;

    while ((ch = getchar()) != '\n')
    {
        p[idx++] = (char)ch;
    }
    p[idx] = '\0';
}

int main(void)
{
    char str[SIZE];
    char strLower[SIZE];
    printf("Please enter the string you would like to check.");

    sgets(str);
    // printf("The string (%s)\n", str);
    int len;
    for (len = 0; str[len] != '\0'; len++)
    ;

    int idx_start = 0;
    int idx_end = len;

    while (idx_start < idx_end)
    {
        if (isalnum(str[idx_start]) && isalnum(str[idx_end]))
        {
            // Both positions are alphanumeric.
            if (tolower(str[idx_start]) != tolower(str[idx_end]))
            {
                printf("The string (%s) is not a palindrome\n", str);
                return 0;
            }
            else{
                ++idx_start;
                --idx_end;
            }
        }
        else if (isalnum(str[idx_start]) && !isalnum(str[idx_end]))
        {
            --idx_end;
        }
        else if (!isalnum(str[idx_start]) && isalnum(str[idx_end]))
        {
            ++idx_start;
        }
        else
        {
            ++idx_start;
            --idx_end;
        }
    }
    printf("The string (%s) is a palindrome\n", str);
}