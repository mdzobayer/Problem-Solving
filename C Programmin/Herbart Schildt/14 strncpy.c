#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char str1[128], str2[80];
    gets(str1);

    int length = strlen(str1);
    strncpy(str2, str1 + (length - 1), 1);
    printf("%s\n",str2);
    //printf("Length is %d\n",length);
    int value = atoi(str2);
    return (0);
}
