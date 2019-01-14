#include <stdio.h>

int main() {
    int number, i, isPrime;

    printf("Enter the number for test: ");
    scanf("%d",&number);

    isPrime = 1;

    for(i = 2; i<=(number/2); ++i) {
        if((number % i) == 0) {
            isPrime = 0;
        }
    }
    if(isPrime == 1) {
        printf("%d is prime number.\n",number);
    }
    else
        printf("%d is not a prime number.\n");

}
