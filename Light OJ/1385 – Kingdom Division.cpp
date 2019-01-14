#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, test;
    double a, b, c, e, f, d;
    bool isZero;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%lf %lf %lf", &a, &b, &c);
        isZero = false;

        if(b != 0)
            e = (a * c) / b;
        else
            isZero = true;

        f = (a + e) * (c + e);

        if(b != e)
            f = f / (b - e);
        else
            isZero = true;
        e = e + f;
        if (isZero || e < 0)
            printf("Case %d: -1\n", t);

        else printf("Case %d: %.10f\n", t, e);

    }

    return (0);
}
