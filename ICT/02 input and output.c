#include <stdio.h>

main()
{
    float c,f;
    printf("Enter temparature in celcius : ");
    scanf("%f",&c);
    f=9*c/5+32;
    printf("The tempearture in farenheit is : %0.2f",f);
    return 0;
}
