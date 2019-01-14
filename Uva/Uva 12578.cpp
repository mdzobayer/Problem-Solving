#include <cstdio>
#include <cmath>
#define PI acos(-1.0)

int main() {

    int t;
    double len, width, radius, aRactangle, aCircle;
    scanf("%d", &t);
    while(t--) {
        scanf("%lf", &len);
        width = (6 * len) / 10;
        radius = (len / 5);
        aRactangle = len * width;
        aCircle = PI * (radius * radius);

        printf("%0.2lf %0.2lf\n", aCircle, (aRactangle - aCircle));
    }

    return (0);
}
