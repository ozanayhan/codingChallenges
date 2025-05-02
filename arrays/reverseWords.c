// Writes a two-word string in reverse order, but without using an additional array.

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
    printf("Please enter two words with a space between them.");

    sgets(str);
    printf("The initial string (%s)\n", str);
    // Obtain the length of string.
    int len;
    for (len = 0; str[len] != '\0'; len++)
    ;

    // Reverse the entire string, and obtain the position of the space.
    int idxSpace = 0;
    char temp;
    for (int i = 0; i < len/2; i++)
    {
        if (isspace(str[i]))
        idxSpace = i;
        if (isspace(str[len - i - 1]))
        idxSpace = len - i - 1;
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    // Position of the space moves after reversing the array to the following position.
    idxSpace = len - idxSpace - 1;

    // Reverse the first word.
    for (int i = 0; i < idxSpace/2; i++)
    {
        temp = str[i];
        str[i] = str[idxSpace - i - 1];
        str[idxSpace - i - 1] = temp;
    }
    // Reverse the second word.
    for (int i = 0; i < (len - idxSpace)/2; i++)
    {
        temp = str[i + idxSpace + 1];
        str[i + idxSpace + 1] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("The new string (%s)\n", str);
}