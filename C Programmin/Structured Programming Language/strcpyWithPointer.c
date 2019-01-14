#include <stdio.h>
#include <string.h>

int main() {

    char* str1 = "Bangladesh Bogus Party";
    char* str2 = "Sad is a Beautiful country";

    strcpy((str1 + 11),(str2 + 4));
    strcat(str1, "! !!!! !!");

    printf("\n%s\n",*str1);

    return (0);
}
