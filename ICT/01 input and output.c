#include <stdio.h>

main()
{
    int a,b,sum;
    float avg;
    printf("Enter 1st number: ");
    scanf("%d",&a);
    printf("Enter 2nd number: ");
    scanf("%d",&b);
    sum=a+b;
    avg=sum/2;
    printf("Sum is : %d\nAverage is : %.2f\n",sum,avg);
    return 0;
}
