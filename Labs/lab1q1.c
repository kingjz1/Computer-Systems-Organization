#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isInteger(char *c);

int main(int argc, char *argv[]) {

    if(argc!=4){
        printf("Please enter exactly 3 arguments.\n");
        return -1;
    }

    int i;

    for (i=1;i<argc;i++){
        if(isInteger(argv[i])==-1){
            printf("Please enter valid integer inputs.\n");
            return -1;
        }
    }

    int start = atoi(argv[1]);
    //printf("start: %d\n",start);
    int end = atoi(argv[2]);
    //printf("end: %d\n",end);
    int incr = atoi(argv[3]);
    //printf("incr: %d\n",incr);

    printf("%d, ",start);

    for (i=1;(start+i*incr)<end;i++){
        printf("%d, ",start+i*incr);
    }

    printf("%d\n",end);

    return 0;
}

/*
 * returns 1 if is an integer; returns -1 otherwise
 */
int isInteger(char *c){
    if(*c=='-'){
        c++;
        for( ;*c!='\0';c++){
            if(!isdigit(*c)){
                return -1; //the argument char string is not an integer
            }
        }
        return 1;//the argument string is an integer
    }

    for( ;*c!='\0';c++){
        if(!isdigit(*c)){
            return -1; //the argument char string is not an integer
        }
    }
    return 1;//the argument string is an integer
}
