#include <stdio.h>
#include <stdlib.h>

// structs
struct node2d {
    struct node1d *first;
    char *name;
    struct node2d *down;
};
struct node1d {
    struct node1d *next;
    char *name;
};

// functions in this file
struct node1d *mk1dNode(char *name, struct node1d *next);
struct node2d *mk2dNode(struct node1d *first, char *name, struct node2d *down);
struct node2d *mkExConfig ();

// enhanced routines
void printConfig(struct node2d *p2d);
void print2d(struct node2d *p2d);
int print1d(struct node1d *p1d);

// main
int main (int argc, char *argv[]) {
    struct node2d *p2d;
    p2d = mkExConfig();//the default configuration given by the sample code (this default configuration is not in order)
    printConfig(p2d);
    return 0;
}

// functions in this file
struct node2d *mkExConfig() {
    struct node1d *p1d;
    struct node2d *p2d;

    // create rows from bottom to top

    // create bottom row from right to left
    p1d = mk1dNode("c3pO", NULL);
    p1d = mk1dNode("cso", p1d);
    p2d = mk2dNode(p1d, "R2D2", NULL);

    // create middle row
    p2d = mk2dNode(NULL, "alice", p2d);

    // create top row from right to left
    p1d = mk1dNode("e342", NULL);
    p1d = mk1dNode("sally", p1d);
    p1d = mk1dNode("xy2", p1d);
    p2d = mk2dNode(p1d, "joe", p2d);

    return p2d;
}
struct node1d *mk1dNode(char *name, struct node1d *next) {
    struct node1d *p1d;
    p1d = (struct node1d *)malloc(sizeof(struct node1d));
    (*p1d).next = next;   // (*p1d). is long form
    p1d->next = next;     // common abbreviation
    p1d->name = name;
    return p1d;
}
struct node2d *mk2dNode(struct node1d *first, char *name, struct node2d *down) {
    struct node2d *p2d;
    p2d = (struct node2d *)malloc(sizeof(struct node2d));
    p2d->first = first;
    p2d->name  = name;
    p2d->down  = down;
    return p2d;
}

// enhanced routines
void printConfig(struct node2d *p2d){
    print2d(p2d);
}
void print2d(struct node2d *p2d){
    int nump2d = 0;
    int nump1d = 0;
    int temp = 0;
    int isFirst = 1;
    if (p2d != NULL){
        nump2d++;
        printf("The %s 2d node has name: %s\n", isFirst?"first":"next", p2d->name);
        struct node1d *p1d = p2d->first;
        temp = print1d(p1d);
        nump1d = nump1d + temp;
        while(p2d->down != NULL){
            isFirst=0;
            nump2d++;
            p2d = p2d->down;
            printf("The %s 2d node has name: %s\n", isFirst?"first":"next", p2d->name);
            p1d = p2d->first;
            temp = print1d(p1d);
            nump1d = nump1d + temp;
        }
    }
    printf("All finished.\n");
    printf("Number of 2d nodes: %d \tNumber of 1d nodes: %d\n", nump2d,nump1d);
}
int print1d(struct node1d *p1d){
    int p1dCounter = 0; //counts the number of 1d nodes start with p1d till the end of the sublist
    int isFirst = 1;
    if (p1d != NULL){
        p1dCounter++;
        printf("\tThe %s 1d node has name: %s", isFirst?"first":"next", p1d->name);
        while(p1d->next != NULL){
            isFirst = 0;
            p1dCounter++;
            p1d=(p1d->next);
            printf("\tThe %s 1d node has name: %s", isFirst?"first":"next", p1d->name);
        }
        printf("\n");
    }
    return p1dCounter;
}