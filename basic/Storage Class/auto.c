//Calculate factorial of an integer quantity

#include <stdio.h>
long int factorial(int n);
int main()
{
    auto int n;
    printf("\nEnter a number: ");
    scanf("%d",&n);
    printf("\n\n%d! = %ld\n",factorial(n));
    return (0);
}
long int factorial(auto int n){
    auto int i;
    auto long int prod = 1;
    if(n>1){
        for(i=2;i<=n;++i){
            prod = prod * i;
        }
    }
    return (prod);
}
