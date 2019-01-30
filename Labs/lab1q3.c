#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char alphaTransform(char c);

int main(int argc, char *argv[]) {

    char c;
    printf("Program starts. Enter anything:\n");
    while((c=getchar()) != EOF){

        if(!isalpha(c)){
            putchar(c);
        }
        else{
            putchar(alphaTransform(c));
        }

    }

    return 0;
}

char alphaTransform(char c){
    return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : (c - 'a' + 'A');
}
