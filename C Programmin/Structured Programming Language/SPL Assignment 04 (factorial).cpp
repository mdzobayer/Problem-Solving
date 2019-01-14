/* Program to display n! (factorial)*/
#include <stdio.h>

int main() {
    int number, result;
    printf("Enter an integer for Factorial: ");
    scanf("%d",&number);
    result = number;
    putchar('\n');
    while ( number > 1) {
        printf("%d x ",number);
        --number;
        result = result * number;
    }
    printf("1 = %d\n",result);

    return (0);
}
