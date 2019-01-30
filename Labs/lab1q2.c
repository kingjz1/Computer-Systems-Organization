#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>

int isPrime(int x);
int isInteger(char *c);


int main(int argc, char *argv[]) {

    int i;

    if (argc!=3){
        printf("Please enter exactly two command-line arguments.\n");
        return -1;
    }

    for (i=1;i<argc;i++){
        if(isInteger(argv[i])==-1){
            printf("Please enter valid integer inputs.\n");
            return -1;
        }
    }


    int lo = atoi(argv[1]);
    int hi = atoi(argv[2]);

    if(lo>hi){
        printf("Lower value cannot be larger than higher value.\n");
        return -1;
    }

    for (i=lo;i<=hi;i++){
        if (isPrime(i)==-1){
            printf("%d is invalid\n", i);
        }
        else if(isPrime(i)==1){
            printf("%d is prime\n", i);
        }
        else{
            printf("%d is not prime\n", i);
        }
    }


    return 0;
}


int isPrime(int x){

    if(x<2 || x>1000){//the input is erroneous
        return -1;
    }

    int i;

    for (i=2;i<x;i++){
        if(x%i==0){
            return 0;//x is not a prime number
        }
    }
    return 1;//x is a prime number
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