#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_LEN 100

void detab(char s[], char t[]);
void entab(char s[], char t[]);

int main(int argc, char *argv[]) {
    if (argc != 2){
        printf("Please enter exactly one command line argument.");
        exit(0);
    }

    if( (strcmp(argv[1], "-en")!=0) && (strcmp(argv[1], "-de")!=0) ){
        printf("Invalid argument.");
        exit(0);
    }
    else if (strcmp(argv[1], "-de") == 0) {
        char sentence[MAX_LEN];// "hi\thow are you"
        char detabS[MAX_LEN];

        printf ("Enter a sentence: \n"); //here if \n is not added, then the line won't be printed on terminal
        scanf("%[^\n]s",sentence);
        printf ("Original sentence:\n %s\n", sentence);

        detab(detabS,sentence);
        printf ("After deTab:\n %s\n", detabS);
    }
    else{
        char sentence[MAX_LEN];//"hi\\thow are you"
        char entabS[MAX_LEN];

        printf ("Enter a sentence: \n");
        scanf ("%s", sentence);
        printf ("Original sentence:\n %s\n", sentence);

        entab(sentence,entabS);
        printf ("After enTab:\n %s\n", entabS);
    }


    return 0;
}

//when copy from t to s
void detab(char s[], char t[]){
    int i, j;

    for (i = 0, j = 0; t[i]!='\0';i++) {
        if (t[i] == '\t') {
            s[j] = '\\';
            j++;
            s[j] = 't';
            j++;
        } else {
            s[j] = t[i];
            j++;
        }
    }
}

//when reverse back from s to t
void entab(char s[], char t[]){
    int i, j;

    for (i = 0, j = 0; s[i]!='\0';i++) {
        switch (s[i]) {
            case '\\':
                /*
                if(s[i+1]=='n'){
                    t[j] = '\n';
                    j++;
                    i++;
                }
                 */
                if(s[i+1]=='t') {
                    t[j] = '\t';
                    j++;
                    i++;
                }
                else{
                    t[j] = s[i];
                    j++;
                }
                break;
            default:
                t[j] = s[i];
                j++;
        }
    }
}


