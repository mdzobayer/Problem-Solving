#include <cstdio>
#include <cmath>

int main() {

    double val = -1.0;

    do {
        printf("Cosine of %f is %f.\n", val, cos(val));
        val += 0.1;
    } while(val <= 1.0);

    printf("\nSine of %f is %f.\n\n", 90.0, sin(90.0));

    return (0);
}
