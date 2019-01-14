#include <stdio.h>

int main(void){
    int a=55;
    int *b;

    b = &a;

    printf("Address %x contains Value = %d\n",b,*b);


    return 0;
}
