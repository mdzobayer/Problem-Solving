/* C program to find LCM of two positive integers entered by user */
#include <stdio.h>
#define TRUE 1
int main()
{
    int num1, num2, max;
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);
    max=(num1 > num2) ? num1 : num2;
    while(TRUE)
    {
        if(max % num1 == 0 && max % num2 == 0)
        {
            printf("LCM of %d and %d is %d", num1, num2,max);
            break;
        }
        ++max;
    }
    return 0;
}
