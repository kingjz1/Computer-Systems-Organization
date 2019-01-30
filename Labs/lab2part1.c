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

// functions in the sample code that are implemented by me
void printConfig(struct node2d *p2d);
void print2d(struct node2d *p2d);
void print1d(struct node1d *p1d);

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


void printConfig(struct node2d *p2d){
    print2d(p2d);
}
void print2d(struct node2d *p2d){
    struct node1d *p1d;
    while(p2d!= NULL){
        printf("2d node name=%s\n", p2d->name);
        p1d = p2d->first;
        print1d(p1d);
        p2d = p2d->down;
    }
    printf("All finished.\n");
}
void print1d(struct node1d *p1d){
    int isEmpty = 1;
    while(p1d!= NULL){
        isEmpty = 0;
        printf("\t1d node name=%s", p1d->name);
        p1d=(p1d->next);
    }
    if(!isEmpty){
        printf("\n");
    }
}