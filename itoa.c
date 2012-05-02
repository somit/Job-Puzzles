#include <stdio.h>
#include <stdlib.h>

char* itoa(int x) {
    int i = x < 0 ? 3 : 2;
    int t = abs(x);
    while (t = t / 10) ++i;
    char *s;
    s= (char *)malloc(i*sizeof(char));
    s[--i] = '\0';
    t = abs(x);
    while (i) s[--i] = '0' + (t % 10), t = t / 10;
    if (x < 0) s[0] = '-';
    return s;
}

main()
{
int i= -324;
char *t;
t=itoa(i);
printf("%s",t);
}
