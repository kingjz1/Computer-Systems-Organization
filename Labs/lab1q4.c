#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void sortInt(int n, int A[n]);
int getInt(void);

int main(int argc, char *argv[]) {

    int N,i;

    printf("Please enter a positive integer N: \n");
    N = getInt();
    //scanf ("%d",&N);
    //printf("N: %d\n",N);

    if(N<=0 || N>=100){//Checks that 0<N<100.
        printf("The input integer should range from 0<N<100.\n");
        return -1;
    }

    //-------------------------------------Reads N more integers into an array.
    int A[N];

    for (i=1;i<=N;i++){
        printf("Please enter element %d of the int array: \n",i);
        A[i-1] = getInt();
        //scanf ("%d",&(A[i-1]));
        //printf("Element %d: %d\n",i, A[i-1]);
    }

    //-----------------------------------
    printf("Original array:\n");//Prints the contents of the original array, one number per line.
    for(i=0;i<N;i++){
        printf("%d\n",A[i]);
    }

    sortInt(N,A);//Sort the array

    printf("Sorted array:\n");//Prints the sorted array, one number per line.
    for(i=0;i<N;i++){
        printf("%d\n",A[i]);
    }

    return 0;
}

void sortInt(int n, int A[]){

    int i,j;

    for(i=0;i<n;i++){
        for (j=0;j<n;j++){
            if(A[i] < A[j]){
                int temp=A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }
    }
}

/*
 * this function returns an integer entered by the user
 */
int getInt(void) {
    char c;
    int sign=1;
    int x = 0;

    while (isspace(c=getchar())) {
        if(c=='\n'){
            printf("Please do not enter nothing.\n");
            exit(-1);
        }
    }

    if(c=='-'){
        sign = -1;
    }
    else if(c=='+'){
        sign = 1;
    }
    else if(isdigit(c)){
        x = c-'0';
    }
    else{
        printf("Please enter a valid integer correctly.\n");
        exit(-1);
    }

    while ((c=getchar())!='\n' && (c!=EOF)){
        if((!isdigit(c))){//check whether the number entered is a valid integer
            printf("Please enter a valid integer correctly.\n");
            exit(-1);
        }
        else{
            x = 10 * x + c - '0';
        }
    }

    x = x*sign;

    return x;
}
