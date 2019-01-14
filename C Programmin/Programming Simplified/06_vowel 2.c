//Function to check vowel
#include <stdio.h>

int check_vowel(char a);
int main()
{
    char ch;

    printf("Enter a character: ");
    scanf("%c",&ch);

    check_vowel(ch);

    if(ch == '1')
        printf("%c is a vowel.\n",ch);

    else
        printf("%c is not a vowel.\n",ch);

    return (0);
}

int check_vowel(char a){
    if(a >= 'A' && a <= 'Z')
        a = a + 'a' - 'A';

    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        return '1';

    return '2';
}
