#include <stdio.h>

int main()
{
    float r,radius;
    printf("Enter radius of the circle (in cm): ");
    scanf("%f",&r);
    radius=3.1415*r*r;
    printf("Radius of circle (in cm): %0.2f\n",radius);
    return 0;
}
