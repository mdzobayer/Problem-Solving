#include <cstdio>

int min(int x, int y) {
    return x < y ? x : y;
}
int max (int x, int y) {
    return x > y ? x : y;
}

struct point {
    int x, y;
};

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, t, i, j, k, l, first, second, third;
    point a, b, c, d;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
        scanf("%d %d %d %d", &c.x, &c.y, &d.x, &d.y);

        i = max (a.x, c.x);
        j = max (a.y, c.y);

        k = min (b.x, d.x);
        l = min (b.y, d.y);

        first = (b.x - a.x) * (b.y - a.y);
        second = (d.x - c.x) * (d.y - c.y);
        third = (k - i) * (l - j);
        //printf("Values %d %d %d %d\n", i, j, k, l);
        printf("Night %d: ", t);
        if (i >= k || j >= l) {
            printf("0 %d %d\n", first + second, 10000 - (first + second));
        }
        else
            printf("%d %d %d\n", third, (first + second) - third - third, 10000 - (first + second - third));
    }

    return (0);
}
