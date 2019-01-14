#include <cstdio>
#include <cmath>
#define pi acos(-1)
int main() {

    double a, b, c, s, triangle, r, roses, violet, r2, sunF;
    while(scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        s = (a + b + c) * 0.5;
        triangle = sqrt(s*(s-a)*(s-b)*(s-c));
        r = triangle / s;
        roses = pi * (r * r);
        violet = triangle - roses;
        r2 = (a * b * c)/(4 * triangle);
        sunF = pi * (r2 * r2) - triangle;
        printf("%0.4lf %0.4lf %0.4lf\n", sunF, violet, roses);
    }

    return (0);
}
