//Add digits using recursion
#include <stdio.h>

int add_digits(int);

int main()
{
    int n, result;

    scanf("%d",&n);

    result = add_digits(n);

    printf("%d\n",result);

    return (0);
}

int add_digits(int n){
    static int sum = 0;

    if(n == 0){
        return 0;
    }

    sum = n % 10 + add_digits(n / 10);

    return sum;
}
