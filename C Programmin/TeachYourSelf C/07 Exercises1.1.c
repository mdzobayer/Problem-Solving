// Not a function prototype
#include <stdio.h>

double avg() {
    double sum = 0;
    double inputFloat;
    double average;
    int i;
    for (i = 0; i < 10; ++i) {
        printf("Enter number %d : ",(i + 1));
        scanf("%lf",&inputFloat);
        sum += inputFloat;
    }
    average = sum / 10;

    return (average);
}
int main() {
    double average;
    average = avg();
    printf("Average is %lf\n",average);

    return (0);
}

