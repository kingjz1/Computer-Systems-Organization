#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
 * If the program name is lower, then the program converts upper case to lower
 * If the program name is upper, then the program converts lower case to upper
 */


int main(int argc, char *argv[]) {

    char *name = argv[0];
    name+=2;
    //printf("Invoke name: %s\n",name);
    if(strcmp(name, "lower") == 0){
        char c;
        while ((c=getchar())!=EOF){
            putchar(tolower(c));
        }
    }
    else if(strcmp(name, "upper") == 0){
        char u;
        while ((u=getchar())!=EOF){
            putchar(toupper(u));
        }
    }
    else{
        printf("Invoked with invalid name.\n");
        return -1;
    }

    return 0;
}