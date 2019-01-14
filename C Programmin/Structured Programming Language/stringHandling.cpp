/** String Handling Functions
    01. strlen();
    02. strcpy();
    03. strcmp();
    04. strcat();
    05. strchr();
    06. strrev();
    07. strstr();
    08. strlwr();
    09. strupr();
    10. strset();
**/
#include <stdio.h>
#include <string.h>

int main() {

    int len1;
    char str1[100], str2[100], str3[100], tempStr1[50];
    char *p;

    printf("Enter 1st string: ");
    gets(str1);
    len1 = strlen(str1);
    printf("\nThe length of the string is %d \n", len1);
    strcpy(str2, str1);
    printf("\nFirst string is : %s and copied string is : %s \n",str1, str2);

    printf("\nEnter the string to be compared with first string: ");
    gets(str3);
    if (strcmp(str1,str3) == 0)
        printf("\nBoth string are equal\n");
    else if (strcmp (str1, str3) < 0)
        printf("\nFirst string is less then second string\n");
    else
        printf("\nFirst string is grater then second string\n");

    printf("\nEnter the string to be concatenated at the right of first string: ");
    gets(tempStr1);
    strcat(str1, tempStr1);
    printf("\nThe concatenated string is %s\n",str1);

    p = strchr(str1, 'a');
    if (p)
        printf("\n%s, here \'%c\' is found\n",str1,*p);
    else
        printf("\nNO match for %c\n",*p);

    strrev(str1);
    printf("\nAfter reverse %s\n", str1);

    p = strstr(str1, "yab");
    if (p)
        printf("\n%s, here \"%s\" is found\n",str1, "yab");
    else
        printf("\nNO match for %s\n", "yab");

    strlwr(str1);
    printf("\nIn Lower case : %s\n",str1);
    strupr(str1);
    printf("\nIn Upper case : %s\n",str1);
    strset(str1, 'Z');
    printf("\nAfter set Z for all character: %s\n", str1);

    return (0);
}
