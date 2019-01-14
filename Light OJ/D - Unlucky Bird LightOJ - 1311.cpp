#include <cstdio>
#include <algorithm>


int main() {

    int test, t;
    double v1, v2, v3, a1, a2, s1, s2, t1, t2;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);

        s1 = (v1 * v1) / (2.0 * a1);
        s2 = (v2 * v2) / (2.0 * a2);

        t1 = v1 / a1;
        t2 = v2 / a2;

        printf("Case %d: %0.6lf %0.6lf\n", t, (s1 + s2), std::max(t1, t2) * v3);
    }

    return (0);
}
