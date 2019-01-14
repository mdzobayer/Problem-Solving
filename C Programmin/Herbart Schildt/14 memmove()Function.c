#include <stdio.h>
#include <string.h>
#define SIZE 80

int main()
{
    char str[SIZE], *p;

    strcpy(str, "When, in the course of...");
    p = str + 10;

    memmove(str, p, SIZE);
    printf("result after shift: %s", str);

    return (0);
}
