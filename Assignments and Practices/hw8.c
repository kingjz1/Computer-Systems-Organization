#include <stdio.h>
#include <math.h>
#define MAXVAL 10000
#define ARRAYBOUND (MAXVAL+1)
#define NUMEMPLOYEES 2

int G[ARRAYBOUND];
int P[ARRAYBOUND];

struct gameValType1 {
    int G[ARRAYBOUND];
    int P[ARRAYBOUND];
} gameVal1;

struct gameValType2 {
    int G;
    int P;
} gameVal2[ARRAYBOUND];

struct employeeType {
    int id;
    char gender;
    double salary;
} employee[NUMEMPLOYEES] = {
        { 32, 'M', 1234. },
        { 18, 'F', 1500. }
};

struct point {
    double x;
    double y;
};

struct rectangle {
    struct point ll;
    struct point ur;
};

struct rectangle mkRectangle1(struct point ll, struct point ur);
struct rectangle mkRectangle2(double llx, double lly, double urx, double ury);

int main() {

    //Test mkmkRectangle
    struct point pt1 = {20.0,40.0};
    struct point pt2 = {30.0,50.0};

    printf("pt1x: %.1f, pt1y: %.1f\n", pt1.x, pt1.y);
    printf("pt2x: %.1f, pt2y: %.1f\n", pt2.x, pt2.y);
    struct rectangle rect1 = mkRectangle1(pt1,pt2);
    printf("rect1:\nllx: %.1f, lly: %.1f, urx: %.1f, ury: %.1f\n", rect1.ll.x, rect1.ll.y, rect1.ur.x,rect1.ur.y);
    struct rectangle rect2 = mkRectangle2(20.0,40.0,30.0,50.0);
    printf("rect2:\nllx: %.1f, lly: %.1f, urx: %.1f, ury: %.1f\n", rect2.ll.x, rect2.ll.y, rect2.ur.x,rect2.ur.y);


    //Question 2
    printf("The size of the type gameValType1 is: %ld\n", sizeof(struct gameValType1));
    printf("The size of the type gameValType2 is: %ld\n", sizeof(struct gameValType2));
    printf("The size of the object employee is: %ld\n", sizeof employee);


    return 0;
}


struct rectangle mkRectangle1(struct point ll, struct point ur){
    struct rectangle rect;

    rect.ll.x = ll.x;
    rect.ll.y = ll.y;
    rect.ur.x = ur.x;
    rect.ur.y = ur.y;

    /* Also works
    rect.ll = ll;
    rect.ur = ur;
    */

    return rect;
}


struct rectangle mkRectangle2(double llx, double lly, double urx, double ury){
    struct rectangle rect;
    rect.ll.x = llx;
    rect.ll.y = lly;
    rect.ur.x = urx;
    rect.ur.y = ury;
    return rect;
}

