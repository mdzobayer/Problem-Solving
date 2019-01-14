
#include <stdio.h>


int main()
{
    int a = 55;
    int *b;
    b = &a;

    printf("Value of a = %d\n",a);
    printf("Address of a = %d",b);

    return 0;
}
