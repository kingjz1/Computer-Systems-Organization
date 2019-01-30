#include <stdio.h>
#include <ctype.h>

int main( )
{
    printf("First Question:\n");
    printf("The value of EOF is %d\n", EOF);


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
