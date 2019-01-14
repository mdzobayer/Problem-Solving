/*program to calling function using string */
#include <stdio.h>

int main()
{
    char c[50];
    printf("Enter string: ");
    gets(c);
    Display(c);
    return 0;
}
void Display(char ch[]){
    printf("String Output: ");
    puts(ch);
}
