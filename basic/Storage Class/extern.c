#include <stdio.h>

int first = 10, last = 15;

int main(){
    extern int first,last;

    printf("%d and %d",first,last);

    return (0);
}
