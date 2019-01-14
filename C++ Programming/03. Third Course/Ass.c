#‎include‬ <stdio.h>
void calculate(float a, float b) {
    printf("--------Result------\n");
    printf("Addition = %f\n", a + b);
    printf("Subtraction = %f\n", a - b);
    printf("Multiplication = %f\n", a * b);
    printf("Division = %f\n", a / b);
};
int main() {
    float number1, number2;
    printf("Enter 1st number: ");
    scanf("%f",&number1);
    printf("Enter 2nd number: ");
    scanf("%f",&number2);
    calculate(number1,number2);
    return (0);
};
