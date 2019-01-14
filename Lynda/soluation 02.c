#include <stdio.h>

int main()
{
    float fahrenheit;
    int kelvin,celcius;

    printf("Celcus is 0(degree)");
    celcius = 0;
    fahrenheit = celcius*(9/5)+32;
    kelvin = celcius + 273;
    printf("Fahrenheit %.2f and Kelvin %d\n",fahrenheit,kelvin);

    printf("Celcus is 100(degree)");
    celcius = 100;
    fahrenheit = celcius*(9/5)+32;
    kelvin = celcius + 273;
    printf("Fahrenheit %.2f and Kelvin %d\n",fahrenheit,kelvin);

    return 0;
}
