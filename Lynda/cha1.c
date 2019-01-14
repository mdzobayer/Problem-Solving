 #include <stdio.h>

int main(void){

    double height,hInch;
    int hFeet;
    printf("Enter height (in centimeter): ");
    scanf("%lf",&height);

    hInch = height*0.393700787;
    hFeet = height*0.032808895;
    double delta = hInch-(hFeet*12);

    printf("Height in Inches: %.1f\n",delta);
    printf("Height in Feet: %d\n",hFeet);

    return 0;

}
