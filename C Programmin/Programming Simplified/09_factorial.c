//Factorial program in c using for loop
#include <stdio.h>

int main()
{
    int c, n, fact = 1;

    printf("Enter a number to calculate it's factorial: ");
    scanf("%d",&n);

    for(c = 1; c <= n; c++)
        fact = fact * c;

    printf("Factorial of %d = %ld\n",n,fact);

    return (0);
}
