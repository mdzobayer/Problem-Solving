#include <stdio.h>

int main()
{
    int n,x;
    float sum;
    printf("Enter the value of n.\n");
    scanf("%d",&n);
    sum=0;
    printf("1");
    for(x=1;x<=n;x++)
    {
        printf("+1/%d",x+1);
        sum=sum+(1.0/x);


    }
    printf(" = %0.03f",sum);
    return 0;
}
