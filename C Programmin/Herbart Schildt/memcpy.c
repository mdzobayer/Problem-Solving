#include <stdio.h>
#include <string.h>

#define SIZE 80

int main()
{

    char buf1[SIZE], buf2[SIZE];

    strcpy(buf1, "When, in the course of ...\n");
    memcpy(buf2, buf1, SIZE);
    strncpy(buf2, buf1, SIZE);
    memmove(buf2, buf1, SIZE);

    printf(buf1);
    printf(buf2);

    char str[SIZE], *p;

    strcpy(str, "When, in the course of ...");
    p = str + 10;

    memmove(str, p, SIZE);
    printf("\nresult after shift: %s\n", str);

    return (0);
}
