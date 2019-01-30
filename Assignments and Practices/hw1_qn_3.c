//
// Created by Junzhang Wang on 9/10/18.
//

#include <stdio.h>
#include <ctype.h>

int main( )
{
    printf("Third Question:\n");
    printf("Please enter some input:\n");
    int b;
    int not_letter = 0;//initially set not_letter as false
    while ((b=getchar()) != EOF){

        if ((b==' ' || b == '\n' || b == '\t' || ispunct(b) != 0) && not_letter == 0){
            printf("\n");
            not_letter = 1;
        }
        else if ((b==' ' || b == '\n' || b == '\t' || ispunct(b) != 0) && not_letter == 1){
            continue;
        }
        else{
            putchar(b);
            not_letter = 0;
        }
    }

    return 0;
}

