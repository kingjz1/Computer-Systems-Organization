#include <stdio.h>

//Question 1
int odd (int x){
    return (x % 2 == 1) ? (1) : (0);
}

//Question 2
void rotate3(int *A, int *B, int *C){
    int temp = *A;
    *A = *B;
    *B= *C;
    *C = temp;
}

//Question 3
void plusminus(int *x,int *y){
    int oldX = *x;
    int oldY = *y;
    *x = oldX + oldY;
    *y = oldX - oldY;
}


int main() {

    //Test odd
    int x = 7;
    printf("%d is %s\n", x, (odd(x)==1) ? "odd" : "even");

    //Test rotate
    int a = 1;
    int b = 2;
    int c = 3;
    printf("a is %d, b is %d, c is %d\n", a, b, c);
    rotate3(&a,&b,&c);
    printf("a is %d, b is %d, c is %d\n", a, b, c);

    //Test plusminus
    int X = 10;
    int Y = 3;
    printf("X is %d, Y is %d\n", X, Y);
    plusminus(&X,&Y);
    printf("X is %d, Y is %d\n", X, Y);


    return 0;
}