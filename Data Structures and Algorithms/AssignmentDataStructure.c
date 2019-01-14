/**
    Name: Md. Zobayer Mahmud Khan
    ID: CSE 059 07156
**/
#include <stdio.h>

int main()
{
    int numbers[5], i, max;

    printf("Enter 5 numbers: ");
    for(i = 0; i < 5; i++){
        scanf("%d",&numbers[i]);
    }
    ///-----Searching Maximum Value------
    max = numbers[0];
    for(i = 1; i < 5; i++) {
        if ( numbers[i] > max)
            max = numbers[i];
    }

    ///-----Searching Maximum Value Position-----
    for(i = 0; i < 5; i++){
        if ( max == numbers[i]){
            printf("Maximum Value %d array index is numbers[%d]\n", numbers[i], i);
            break;
        }
    }

    return (0);
}
