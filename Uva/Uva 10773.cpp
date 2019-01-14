#include <cstdio>
#include <cmath>

int main() {
    //freopen("input.txt", "r", stdin);
    int test, t, d, v, u;
    double t1, t2;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d %d", &d, &v, &u);
        printf("Case %d: ", t);
        if (d == 0 || v == 0 || v >= u) {
            printf("can't determine\n");
            continue;
        }
        t1 = (d * 1.0) / u;
        t2 = (d * 1.0) / sqrt((u * u) - (v * v));
        printf("%0.3lf\n", fabs(t1 - t2));
    }

    return (0);
}
