#include <stdio.h>

//Question 1
int getLine(char s[], int lim) {
    int c, i;
    for (i=0; i<lim-1; ++i) {
        c = getchar();
        if(c == '\n'){
            break;
        }
        if(c == EOF){
            break;
        }
        s[i] = c;
    }

    if (c=='\n') {
        s[i]= c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

//Question 2
int htoi (char a[]){
    int n = 0;
    int j;
    for(j = 0; ((a[j]>='0' && a[j]<='9') || (a[j]>='a' && a[j]<='f') || (a[j]>='A' && a[j]<='F')); j++){

        if(a[j]>='0' && a[j]<='9') {
            n = 16*n + (a[j]-'0');
        }
        else if(a[j]>='a' && a[j]<='f'){
            n = 16*n + (a[j] - 'a' + 10);
        }
        else{
            n = 16*n + (a[j] - 'A' + 10);
        }
    }
    return n;
}

//Question3
void squeeze(char str1[], char str2[]){
    int i,j,k;
    int flag;

    j = 0;

    for (i = 0; str1[i] != '\0'; i++){
        flag = 0;
        for (k = 0; str2[k]!='\0' && !flag; k++){
            if (str2[k] == str1[i]){
                flag = 1;
            }
        }
        if (!flag) {
            str1[j] = str1[i];
            j++;
        }
    }
    str1[j] = '\0';
}

//Question4
char lower(char c){
    return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}

int main() {

    //Test getLine using the code on the website

    //Test atoi
    char a[] = "2F";
    printf("%d\n", htoi(a));

    //Test squeeze
    char s1[] = "abcdef";
    char s2[] = "bcf";
    squeeze(s1,s2);
    printf("%s\n",s1);

    //Test lower
    printf("%s\n","Please enter letters with either lower case and upper case: ");
    char c;
    while((c = getchar()) != EOF) {
        putchar(lower(c));
    }
    return 0;
}