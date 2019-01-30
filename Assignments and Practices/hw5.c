#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int  bufp = 0;

int getch(void) {
    return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many chars\n");
    else
        buf[bufp++] = c;
}

//Question 1
//Below is the revised getint method
int getint(int *pn) {
    int c, sign;
    while (isspace(c=getch())) ;//skip spaces
    if (!isdigit(c) && c!=EOF && c!='+' && c!='-') {//check for legality
        ungetch(c);
        return 0;
    }
    sign = (c=='-') ? -1 : 1;

    if (c=='+' || c=='-') {
        c = getch();
        //if a + or - is not followed by a digit, then the sign character is pushed back and zero will be returned
        if (!isdigit(c)) {
            ungetch(c);
            if (sign == -1) {
                ungetch('-');
            }
            else {
                ungetch('+');
            }
            return 0;
        }

    }

    for (*pn = 0; isdigit(c); c=getch())
        *pn = 10 * *pn + (c-'0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

//Question 2
void changeltox (char s[]) {
    int i;
    for (i=0;s[i]!= '\0';i++) {
        if (s[i] == 'l')
            s[i] = 'x';
    }
}

int main() {
    //Test Question 2
    char a[] = "abdlsdllsll";
    changeltox(a);
    printf("%s\n",a);
    return 0;
}