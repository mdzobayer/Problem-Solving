//Using bitwise or modulus operator

#include <stdio.h>

int main()
{
    int n;

    printf("Enter an integer: ");
    scanf("%d",&n);

    if((n/2)*2 == n)
        printf("Even\n");
    else
        printf("Odd\n");

    return (0);
}
