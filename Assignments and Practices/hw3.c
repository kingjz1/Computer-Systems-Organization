#include <stdio.h>

//when copy from t to s
void escape(char s[], char t[]){
    int i, j;

    for (i = 0, j = 0; t[i]!='\0';i++) {
        switch (t[i]) {
            case '\n':
                s[j] = '\\';
                j++;
                s[j] = 'n';
                j++;
                break;
            case '\t':
                s[j] = '\\';
                j++;
                s[j] = 't';
                j++;
                break;
            default:
                s[j] = t[i];
                j++;
        }
    }
}

//when reverse back from s to t
void unescape(char s[], char t[]){
    int i, j;

    for (i = 0, j = 0; s[i]!='\0';i++) {
        switch (s[i]) {
            case '\\':
                if(s[i+1]=='n'){
                    t[j] = '\n';
                    j++;
                    i++;
                }
                if(s[i+1]=='t') {
                    t[j] = '\t';
                    j++;
                    i++;
                }
                break;
            default:
                t[j] = s[i];
                j++;
        }
    }
}

int main() {

    char a[] = "Hello my friend \n this is good";
    char b[100];
    char c[100];
    printf("%s\n",a);
    escape(b,a);
    printf("%s\n",b);
    unescape(b,c);
    printf("%s\n",c);

    return 0;
}