//
// Created by Junzhang Wang on 9/10/18.
//
#include <stdio.h>
#include <ctype.h>

int main( )
{
    printf("Second Question:\n");
    printf("Please enter some input:\n");
    int a;
    int is_space = 0; //initially the flag is FALSE
    while ((a = getchar()) != EOF) {
        if (a == ' ' && is_space == 0) {
            is_space = 1;
            putchar(a);
        }
        else if (a != ' ') {
            is_space = 0;
            putchar(a);
        }
    }

    return 0;
}
