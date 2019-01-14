#include <stdio.h>

int main() {

    int a, b, sum;
    printf("\n\tWelcome to our calculator\n\n\n");
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);

    sum = a + b;

    printf("Sum is = %d\n",sum);
    sum = a-b;
    printf("Subtract is = %d\n",sum);

    return 0;

}


