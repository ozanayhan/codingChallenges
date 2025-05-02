// Checks whether a user given string is a palindrome or not.

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

    int i;
    int len = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (isalnum(str[i]))
        {
            strLower[len++] = tolower(str[i]);
        }
        
    }
    strLower[len] = '\0';
    for (i = 0; i <= len/2; i++)
    {
        if (strLower[i] != strLower[len - i - 1])
        {
            printf("The string (%s) is not a palindrome\n", str);
            return 0;
        }
    }
    printf("The string (%s) is a palindrome\n", str);
}