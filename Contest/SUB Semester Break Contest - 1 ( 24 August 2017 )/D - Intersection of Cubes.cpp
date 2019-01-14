#include <cstdio>
#include <climits>

int max (int x, int y) {
    return x > y ? x : y;
}

int min (int x, int y) {
    return x < y ? x : y;
}

struct cube {
    int startX, startY, startZ, endX, endY, endZ;
};

cube object[110];

int main() {

    int test, t, n, a, b, c, d, e, f, i;
    scanf("%d", &test);

    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);

        a = b = c = INT_MIN;
        d = e = f = INT_MAX;

        for (i = 0; i < n; ++i) {
            scanf("%d %d %d", &object[i].startX, &object[i].startY, &object[i].startZ);
            scanf("%d %d %d", &object[i].endX, &object[i].endY, &object[i].endZ);

            a = max (object[i].startX, a);
            b = max (object[i].startY, b);
            c = max (object[i].startZ, c);

            d = min (object[i].endX, d);
            e = min (object[i].endY, e);
            f = min (object[i].endZ, f);
        }
        printf("Case %d: ", t);
        //printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
        if (d <= a || e <= b || f <= c)
            printf("0\n");
        else
            printf("%d\n", ((a - d)*(b - e) * (f - c)));
    }

    return (0);
}
