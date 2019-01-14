#include <bits/stdc++.h>

using namespace std;

double pi = 2 * acos(0.0);

int main() {

    double r, line, areaRect, areaCir, result;
    int test, t;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%lf", &r);

        line = r * 2.0;
        areaRect = line * line;
        areaCir = (pi * (r*r));
        result = (areaRect - areaCir);

        printf("Case %d: %0.2f\n", t, result);
    }

    return (0);
}
