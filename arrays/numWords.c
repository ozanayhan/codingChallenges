// Checks how many words exist in a string

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
    printf("Please enter the string you would like to check.");

    sgets(str);
    // printf("The string (%s)\n", str);

    int numWords = 0;
    int isPreviousCharSpace = 1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isPreviousCharSpace && !isspace(str[i]))
        ++numWords;
        isPreviousCharSpace = isspace(str[i]);
    }
    printf("The string (%s) has %d words\n", str, numWords);
}