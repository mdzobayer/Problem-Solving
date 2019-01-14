// Does not require a separate prototype
#include <stdio.h>

float getNumber() {
    float x;
    printf("Enter a number: ");
    scanf("%f", &x);
    return x;
}

int main() {
    float i;

    i = getNumber();
    printf("%f\n", i);

    return (0);

}
