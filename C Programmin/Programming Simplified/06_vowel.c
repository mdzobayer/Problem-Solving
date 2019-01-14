// C program to check whether input alphabet is a vowel or not
#include <stdio.h>

int main(){

    char c;
    printf("Enter a character: ");
    scanf("%c",&c);

    if(c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u')
        printf("%c is a vowel.\n",c);
    else
        printf("%c is not a vowel.\n",c);

    return (0);


}
