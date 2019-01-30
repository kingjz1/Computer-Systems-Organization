#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

// pointer list struct that stores a list of node1d pointers (used for freeing the memory)
struct n1dPointerList {
    struct node1d *n1dPointer;
    struct n1dPointerList *next;
};

// functions in this file
struct node1d *mk1dNode(char *name, struct node1d *next);
struct node2d *mk2dNode(struct node1d *first, char *name, struct node2d *down);
struct node2d *mkExConfig ();

// the same print routines used in part 2
void printConfig(struct node2d *p2d);
void print2d(struct node2d *p2d);
int print1d(struct node1d *p1d);

// new functions added
struct node2d * searchNode2d (struct node2d *p2dRoot, char *n2dName);
struct node1d * insert(struct node2d *p2dRoot, char *listName, char* nodeName);
void appendChar(char *target, char c);
void add1dPointerTo1dPointerList(struct n1dPointerList *n1dPL, struct node1d *n1d);

// main
int main (int argc, char *argv[]) {

    struct node2d *p2d;
    p2d = mkExConfig();//the default configuration given by the sample code (this default configuration is not in order)
    printf("----------------------------Initial Configuration----------------------------\n");
    printConfig(p2d);

    // initialize the 1d pointer list to hold the pointers of any newly inserted 1d nodes
    struct n1dPointerList *n1dPL = (struct n1dPointerList *)malloc(sizeof(struct n1dPointerList));
    n1dPL->n1dPointer=NULL;
    n1dPL->next=NULL;

    char oneLineCommand[1202]; // the char array that will hold the one-line command
    printf("\n-----------The program has started, you can now enter your command-----------\n");
    while(fgets(oneLineCommand, 1202, stdin)!=NULL){
        char *i = oneLineCommand;
        char TwoDNodeName[500] = ""; // the char array that will hold the name of the 2d node to which the user is to add a 1d node
        char OneDNodeName[500] = ""; // the char array that will hold the name of the 1d node the user is to add
        if((*i)!='I' || (*(i+1))!='n' || (*(i+2))!='s' || (*(i+3))!=' '){ // Check if The first four characters are 'Ins '
            printf("Error detected: First four characters are not 'Ins '.\n");
            return 1;
        }
        i = i+4;
        if(!isalnum(*i)){
            printf("Error detected: After 'Ins ', the next N>0 characters must be digits or letters, and the next character follows them must be a blank.\n");
            return 2;
        }
        while(isalnum(*i)){
            appendChar(TwoDNodeName,*i);
            i++;
        }
        if((*i)!=' '){
            printf("Error detected: After 'Ins ', the next N>0 characters must be digits or letters, and the next character follows them must be a blank.\n");
            return 2;
        }
        i++;
        if(!isalnum(*i)){
            printf("Error detected: After you enter the 2d node name and a blank, the next M>0 characters must be digits or letters, and the next character follows them must be a new line.\n");
            return 3;
        }
        while(isalnum(*i)){
            appendChar(OneDNodeName,*i);
            i++;
        }
        if((*i)!='\n'){
            printf("Error detected: After you enter the 2d node name and a blank, the next M>0 characters must be digits or letters, and the next character follows them must be a new line.\n");
            return 3;
        }

        // perform insertion of the 1d node
        struct node1d *p1dPointer = insert(p2d,TwoDNodeName,OneDNodeName);

        // print the updated configuration
        printf("----------------------------Updated Configuration----------------------------\n");
        printConfig(p2d);

        // store the pointer of the newly inserted 1d node to 1d pointer list
        add1dPointerTo1dPointerList(n1dPL,p1dPointer);

        printf("\n------------------You can now enter another line of command------------------\n");
    }

    // when EOF is reached
    printf("You have entered EOF.\n");
    printf("-----------------------------Final Configuration-----------------------------\n");
    printConfig(p2d);

    // free any memory I have previously malloc'ed
    struct n1dPointerList *temp;
    while(n1dPL->n1dPointer!=NULL){
        temp=n1dPL;
        n1dPL=n1dPL->next;
        free(temp->n1dPointer->name);
        free(temp->n1dPointer);
        free(temp);
        if(n1dPL==NULL){
            break;
        }
    }

    // delete all the nodes inserted and recover the initial configuration
    p2d->down->down->first->next->next=NULL;
    p2d->down->first=NULL;
    p2d->first->next->next->next=NULL;

    /*
    printf("\n-------Configuration after freeing and deleting all the inserted nodes-------\n");
    printConfig(p2d);
    */
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

//---------------------------------------------------------------------------------------------------------------------------------
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

void add1dPointerTo1dPointerList(struct n1dPointerList *n1dPL, struct node1d *n1d){
    if (n1dPL->n1dPointer==NULL){
        n1dPL->n1dPointer=n1d;
    }
    else{
        while(n1dPL->next!=NULL){
            n1dPL=n1dPL->next;
        }
        struct n1dPointerList *newn1dPL = (struct n1dPointerList *)malloc(sizeof (struct n1dPointerList));
        newn1dPL->n1dPointer=n1d;
        newn1dPL->next=NULL;
        n1dPL->next=newn1dPL;
    }
}
void appendChar(char *target, char c){//here we assume that the space allocated for target is big enough so we don't need to worry about going out of bounds
    int length = strlen(target);//here it is safe to use int to catch the return value of strlen since length of any string is never negative
    target[length] = c;
    target[length+1] = '\0';
}
struct node2d *searchNode2d (struct node2d *p2dRoot, char *n2dName){
    while(p2dRoot != NULL){
        if (strcmp(p2dRoot->name, n2dName)==0){
            return p2dRoot;
        }
        p2dRoot = p2dRoot->down;
    }
    //return NULL if 2d node with name n2dName was not found
    return NULL;
}
struct node1d *insert(struct node2d *p2dRoot, char *listName, char* nodeName){
    //Search for the 2d node which leads the sub-list where we want to insert the 1d node
    struct node2d * n2d = searchNode2d(p2dRoot,listName);
    if(n2d==NULL){
        printf("Error detected: The 2d node name you entered cannot be found.\n");
        exit(4);
    }

    //Initialize the 1d node that we want to insert
    int len = strlen(nodeName);
    char *nName = malloc((len+1)*sizeof(char));
    strcpy(nName,nodeName);
    struct node1d *p1d = mk1dNode(nName, NULL);

    if(n2d->first==NULL){
        n2d->first = p1d;
    }
    else{
        struct node1d * temp = n2d->first;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = p1d;
    }
    return p1d;
}
