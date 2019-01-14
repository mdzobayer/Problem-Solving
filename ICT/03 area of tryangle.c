#include <stdio.h>

int main()
{
    float base,height,area;
    printf("Enter base in c.m.: ");
    scanf("%f",&base);
    printf("Enter height in c.m.: ");
    scanf("%f",&height);
    area=(base*height)/2;
    printf("Area : %0.2f square c.m.\n",area);
    return 0;
}
