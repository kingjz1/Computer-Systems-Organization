#include <stdio.h>

char *strncpyMyVersion (char *s, char *t, int n) {
    int counter = 1;
    while ((counter<=n) && (*t!=0)){
        *s++ = *t++;
        counter++;
    }
    *s = '\0';
    return s;
}

int main() {
    char s[10];
    char t[] = "TestStringABCDEF";
    strncpyMyVersion(s,t,10);
    printf("%s\n",s);
    return 0;
}