#include <stdio.h>

void rcopy(char *s1, char *s2)
{
    if(*s2 != '\0') {
        *s1++ = *s2++;
        rcopy(s1, s2);
    }
    else {
        *s1 = '\0';
    }
}
/*void print(char *string) {
    while(*string != '\0') {
        putchar(*string);
        *string++;
    }
}*/

int main() {

    char str[80];

    rcopy(str, "this is a test\n");
    printf(str);

    //print("HELLO BANGLADESH %d");

    return (0);
}
