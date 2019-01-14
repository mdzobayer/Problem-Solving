//Program to addition without using third variable
#include <stdio.h>

int main(){

    int a = 1, b = 2;

    //Storing result of addition in variable a

    a = a + b;

    /*
    *Not recommended because original value of a is lost
    * and you may be using it somewhere in code considering it
    * as it was entered by the user.
    */

    printf("Sum of a and b = %d\n",a);

    return (0);
}
