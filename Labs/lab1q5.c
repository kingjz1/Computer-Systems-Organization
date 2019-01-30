#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>

//external arrays
int result[9];
int temp[9];

//function declarations
int countNeighbors (int i, int x[]);
void conway(void);
void printConway(void);
int getInt(void);


int main(int argc, char *argv[]) {

    int extern result[];

    int i;
    
    //Get numGen
    int numGen;
    printf("Please enter the number of generations you want to generate: \n");
    numGen = getInt();

    /* another way to read input
    if (scanf("%d",&numGen)!=1){
        printf ("Please enter a valid integer.\n");
        return -1;
    }
    */


    //Check that numGen is positive and abort the run if it is not
    if(numGen<=0){
        printf ("numGen should be positive.\n");
        return -1;
    }

    //Get the remaining 9 numbers
    for(i=1;i<=9;i++){
        printf ("Please enter element %d of the initial conway matrix:\n",i);

        result[i-1] = getInt();

        /* another way to read input
        if (scanf("%d",&result[i-1])!=1){
            printf("Please enter a valid integer.\n");
            return -1;
        }
        */

        //Check that each of the remaining 9 integers must each be 0 or 1 and abort if not
        if((result[i-1]!=1) && (result[i-1]!=0)){
            printf("Must enter 1 or 0 for the conway matrix inputs.\n");
            return -1;
            //abort();
        }

    }


    //-------------------------------------------
    //Print the zero generation conway
    printf("Generation 0:\n");
    printConway();

    //Loop through each generation
    for (i=1;i<=numGen;i++){
        conway();
        //printf("\n");
        //printf("Generation %d:\n",i);
        //printConway();
    }

    //Stop when reaching generation numGen and print the resulting 3 by 3 matrix on the screen
    printf("\nGeneration %d:\n",numGen);
    printConway();

    return 0;
}

/*
 * Input: int array and the index of the element in the int array
 * returns the number of neighbors around x[i]
 */
int countNeighbors (int i, int x[]){

    int counter = 0;

    switch (i){
        case 0:
            if(x[1]==1){
                counter++;
            }
            if(x[3]==1){
                counter++;
            }
            if(x[4]==1){
                counter++;
            }
            break;
        case 1:
            if(x[0]==1){
                counter++;
            }
            if(x[2]==1){
                counter++;
            }
            if(x[3]==1){
                counter++;
            }
            if(x[4]==1){
                counter++;
            }
            if(x[5]==1){
                counter++;
            }
            break;
        case 2:
            if(x[1]==1){
                counter++;
            }
            if(x[4]==1){
                counter++;
            }
            if(x[5]==1){
                counter++;
            }
            break;
        case 3:
            if(x[0]==1){
                counter++;
            }
            if(x[1]==1){
                counter++;
            }
            if(x[4]==1){
                counter++;
            }
            if(x[6]==1){
                counter++;
            }
            if(x[7]==1){
                counter++;
            }
            break;
        case 4:
            if(x[0]==1){
                counter++;
            }
            if(x[1]==1){
                counter++;
            }
            if(x[2]==1){
                counter++;
            }
            if(x[3]==1){
                counter++;
            }
            if(x[5]==1){
                counter++;
            }
            if(x[6]==1){
                counter++;
            }
            if(x[7]==1){
                counter++;
            }
            if(x[8]==1){
                counter++;
            }
            break;
        case 5:
            if(x[1]==1){
                counter++;
            }
            if(x[2]==1){
                counter++;
            }
            if(x[4]==1){
                counter++;
            }
            if(x[7]==1){
                counter++;
            }
            if(x[8]==1){
                counter++;
            }
            break;
        case 6:
            if(x[3]==1){
                counter++;
            }
            if(x[4]==1){
                counter++;
            }
            if(x[7]==1){
                counter++;
            }
            break;
        case 7:
            if(x[3]==1){
                counter++;
            }
            if(x[4]==1){
                counter++;
            }
            if(x[5]==1){
                counter++;
            }
            if(x[6]==1){
                counter++;
            }
            if(x[8]==1){
                counter++;
            }
            break;
        case 8:
            if(x[4]==1){
                counter++;
            }
            if(x[5]==1){
                counter++;
            }
            if(x[7]==1){
                counter++;
            }
            break;
    }
    return counter;
}

/*
 * do the actual conway iteration once
 */
void conway(void){
    //receive the outcome of the result
    int extern result[];
    int extern temp[];
    int i;
    int intHolder;
    int count;

    //fill in the temp array
    for (i=0;i<9;i++){
        intHolder = result[i];
        temp[i]= intHolder;
    }

    for (i=0;i<9;i++){
        count = countNeighbors(i,temp);
        if((count==2) || (count==3)){
            result[i]=1;
        }
        else{
            result[i]=0;
        }
    }
}

/*
 * print the current conway matrix
 */
void printConway(void){
    int extern result[];
    int i;
    for(i=0;i<9;i=i+3){
        printf("%d\t%d\t%d\n",result[i],result[i+1],result[i+2]);
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