//Factorial program in c using function
#include <stdio.h>
long factorial(int n);
int main()
{
    int number;
    long fact = 1;

    printf("Enter a number to calculate it's factorial: ");
    scanf("%d",&number);

    printf("%d! = %ld\n",number,factorial(number));

    return (0);
}

long factorial(int n){
    int c;
    long result = 1;

    for(c = 1; c <= n; c++)
        result = result *c;

    return result;
}
